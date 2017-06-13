package tw.edu.au.csie.ucan.bee;

publuc class BeeJNI {
	public native int setup();
	public native int keygen();
	public native int enc();
	public native int dec();

	static {System.loadLibrary("bee-cpabe")}
	
	
	
	
}
