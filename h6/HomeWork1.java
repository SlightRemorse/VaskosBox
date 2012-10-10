import java.util.Arrays;

public class HomeWork1 {

	public static void main(String[] args) {
		System.out.println("----------------------------------");
		boolean invert = false;
		if(args[args.length-1].equals("down")) invert = true;
		String Curr = new String();
		int a = 0;
		for(int i=0; i<args.length; i++) {
			if(System.getProperty(args[i])!=null) a++;
		}
		String Display[] = new String[a];
		a = 0;
		for(int i=0; i<args.length; i++) {
			if(System.getProperty(args[i])!=null) {
				Display[a]=System.getProperty(args[i]);
				a++;
			}
		}
		Arrays.sort(Display);
		if(invert==false) {
			for(int i=0; i<Display.length; i++) {
				System.out.println(Display[i]);
			}
		} else {
			for(int i=Display.length-1; i>=0; i--) {
				System.out.println(Display[i]);
			}
		}
	}
}