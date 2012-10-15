import java.util.*;
import java.io.*;

public class Planes {

	public static int spot[][] = new int[27][6];
	public static int counter=0;
	public static boolean found=false;

	public static void Display() {
		for(int line=0; line<27; line++) {
			for(int roll=0; roll<6; roll++) {
				if(roll==3) System.out.print(" ");
				System.out.print(spot[line][roll]);
			}
		System.out.println();
		}
	}
	
	public static void CheckAndAdd(int num) {
		boolean free=false;
		found=false;
		for(int line=0; line<27; line++) {
			for(int roll=0; roll<6; roll++) {
				if(spot[line][roll]==0) {
					if(((roll<=2) && (roll+num>3)) || ((roll>=3) && (roll+num>6))) {
					} else {
						free = true;
						for(int count=0; count<num; count++) if(spot[line][roll+count]==1) free = false;
						if(free==true) {
							for(int count=0; count<num; count++) spot[line][roll+count]=1;
							counter+=num;
						}
					}
				}
			if(free==true) break;
			}
		if(free==true) break;
		}
		if(free==true) found=true;
	}
	
	public static void main(String args[]) {
		Display();
		while(counter<162) {
			int rand=new Random().nextInt(3)+1;
			if(counter+rand<=162) {
				try {
					Thread.sleep(1000);
				} catch(InterruptedException ex) {
					Thread.currentThread().interrupt();
				}
				Display();
				System.out.println("Looking for a spot for " + rand + " passangers.");
				CheckAndAdd(rand);
				System.out.println("Number of passangers now: " + counter);
				if(found==false) System.out.println("Spot not found.");
			}
		}
		Display();
	}
}