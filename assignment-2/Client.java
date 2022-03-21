import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.security.*;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;
import java.util.Base64;
import java.net.Socket;
import java.io.PrintWriter;
import java.io.ByteArrayOutputStream;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
//import RSAUtils.RSAUtils;


public class Client {
    private static final int PORT = 1337;
    private static final String SRVPUBKEY = "MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCDAZzhQdUIHkWLtDIe0rXONPYAwGY8WxiOqc7DAfJL/xoXQkYG0zep766kqkCHFOzuu5EKU2g03QbbWINgxGt6t2LM6ZyqoRJhM7g3mLxZ4TsH5hwElc6eq/KHGRuPE/f/eOmBWAVOVLgKdpHDZGzdA7MZjuvjYEgRhISr3/YKnQIDAQAB";

    private static String privateKey;
    private static String publicKey;
    private static PrintWriter clientOutput;

    private static BufferedReader serverInput;
    private static Socket clienteSocket;
    //private static ServerSocket serverSocket;

    public static void main(String[] args) throws IOException {
      try{
        clienteSocket = new Socket ("127.0.0.1", PORT); //socket for the client
        serverInput = new BufferedReader(new InputStreamReader(clienteSocket.getInputStream()));
        //serverSocket = new ServerSocket(PORT);
        System.out.println("Got Client's connetion: " + clienteSocket);
        clientOutput = new PrintWriter(clienteSocket.getOutputStream(),true); //client-server communication method

        KeyPair keyPair = RSAUtils.getKeyPair(); //get the keypair
        privateKey = new String(Base64.getEncoder().encode(keyPair.getPrivate().getEncoded()), "UTF-8"); //private as a string
        publicKey = new String(Base64.getEncoder().encode(keyPair.getPublic().getEncoded()), "UTF-8"); //public key as a string

        // RSA sign
        String sign = RSAUtils.sign(publicKey, RSAUtils.getPrivateKey(privateKey)); //get PublicSign as a string
        clientOutput.println(sign); //publicSign
        clientOutput.println(publicKey); //publicKeye

        // "[+] Client received Server's AES key: "
        String AESKey = serverInput.readLine().trim();
        String unAESKey = RSAUtils.decryptByPrivateKey(AESKey, RSAUtils.getPrivateKey(privateKey));
        System.out.println("[+] Client received Server's AES key: " + unAESKey);

        // "[+] Client received Server's Random String: "
        String randoStr = serverInput.readLine().trim();
        String randoStr2 = randoStr.substring(0,10);
        System.out.println("[+] Client received Server's Random String: " + randoStr2);
        //enString: ___;
        String enString = serverInput.readLine().trim();
        //String enString2 = RSAUtils.aesDecrypt(enString, unAESKey);
        String sign2 = RSAUtils.sign((AESKey + randoStr), RSAUtils.getPrivateKey(privateKey)); //get
        //String signatureenString = RSAUtils.decryptByPrivateKey(enString, RSAUtils.getPrivateKey(privateKey));
        System.out.println("[+] enString: " + enString);
        System.out.println("[+] enString2: " + sign2);
        System.out.println("[+] Client IP from server: " + randoStr.substring(10,randoStr.length()));

        // "[+] enString: "

        clienteSocket.close();
        //serverSocket.close();

      } catch(Exception e){
        System.out.println(e);
      }

    }
}
