
import sys
import random



if __name__ == "__main__":
	seed = int(sys.argv[1])
	print("Please make sure your UID is " + str(seed) + "; if not, please rerun this program with your correct UID")
	random.seed(seed)

	print("Please pick the following programs for your assignment:")
	
	print("\tStack Buffer Overflow/"+str(random.randint(1, 100))+".c")
	print("\tHeap Buffer Overflow/"+str(random.randint(1, 100))+".c")
	print("\tUse After Free/"+str(random.randint(1, 100))+".c")
	print("\tInteger Overflow/"+str(random.randint(1, 100))+".c")
	print("\tUse of Uninitialized Variable/"+str(random.randint(1, 100))+".c")

