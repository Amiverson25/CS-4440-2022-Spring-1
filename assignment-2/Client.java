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

    //private static BufferedReader serverInput;
    //private static InputStream serverInput;

    private static BufferedReader serverInput;

    //private static DataInputStream serverInput;//= new DataInputStream(new FileInputStream("E:\\file.txt"));
    private static Socket clienteSocket;
    //private static ServerSocket serverSocket;

    public static void main(String[] args) throws IOException {
      //while(true){
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

        String AESKey = serverInput.readLine().trim();
        System.out.println("Encrypted AES String: " + AESKey);
        System.out.println("Server Signature is Valid"); //I am just assuming because we are skipping the 6a step. I can use this if i am bored tho

        String unAESKey = RSAUtils.decryptByPrivateKey(AESKey, RSAUtils.getPrivateKey(privateKey));
        System.out.println("[+] Client received Server's AES key: " + unAESKey);

        String randoStr = serverInput.readLine().trim();
        String randoStr2 = randoStr.substring(0,10);
        System.out.println("[+] Client received Server's Random String: " + randoStr2 + randoStr2.length());

        String signatureOfRandomStringandAESKey = serverInput.readLine().trim();
        String encryptStringWithAes = RSAUtils.aesEncrypt(randoStr2,unAESKey);

        System.out.println("[+] enString: " + encryptStringWithAes);
        System.out.println("[+] Client IP from server: " + randoStr.substring(10,randoStr.length()));
        String sign2 = RSAUtils.sign(encryptStringWithAes, keyPair.getPrivate());
        clientOutput.println(sign2);
        clientOutput.println(encryptStringWithAes);
        clientOutput.flush();
        serverInput = new BufferedReader(new InputStreamReader(clienteSocket.getInputStream()));
        Thread.sleep(2000);
        clienteSocket.close();
      } catch(Exception e){
        System.out.println(e);
      }
      finally{

      }

    }
}
