
public class JNI_a {
    public native static String getStringFromC();
    public native String getStringFromC2();
    public String key="中文";

    /**
     *
     * @return
     */
    public native String getKey();
    public native int getStringLength(String str);
    static {
        System.loadLibrary("JNI_Learn");
    }
    public static void main(String[] arg) {
//        System.out.println(getStringFromC());
        JNI_a a = new JNI_a();
//        System.out.println(a.getStringFromC2());
//        System.out.println("file encode:"+System.getProperty("file.encoding"));
//        // a.getKey();
//        System.out.println(a.key.length());
//        for(int i=0;i<a.key.length();i++){
//            System.out.print(a.key.charAt(i));
//            Integer integer= new Integer(a.key.codePointAt(i));
//            System.out.println(" char code: "+integer);
//        }
        //for (int i=0;i<)
        System.out.println(a.getStringLength("中文"));
        System.out.println(a.getStringLength("I Love 中文"));
        //System.out.println(a.key);
    }


}