import java.text.DecimalFormat;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
public class Main {
    //since . could represent any character in regular expression; so match a poing . should use \\.
//    private static Pattern pattern = Pattern.compile("^-?\\d*(\\.\\d+)?$");
    private static Pattern pattern = Pattern.compile("-?[0-9]+(\\.[0-9]+)?");
    private static boolean isNumber(String str){
        Matcher m = pattern.matcher((str));
        return m.matches();
    }
    private  static  boolean isLegal(String str){
        boolean flag = isNumber(str);
        if(!flag) return  flag;
        int idx = str.indexOf('.');
        if(idx!= -1 && str.length()-idx >3) return false;
        Double val = Double.parseDouble(str);
        if(val<-1000 || val>1000) return false;
        return true;
    }
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int num = 0;
        double val = 0; double sum = 0;
        for(int i=0;i<N;i++){
            String x = scan.next();
            if(isLegal(x)){
                val = Double.parseDouble(x);
                sum = sum + val;
                num = num+1;
            }
            else System.out.println("ERROR: "+ x +" is not a legal number");
        }
        if(num==0) System.out.println("The average of 0 numbers is Undefined");
        else {
            DecimalFormat df = new DecimalFormat("0.00");
            String avg = df.format(sum / num);
            if(num==1) System.out.println("The average of 1 number is "+avg);
            else System.out.println("The average of " + num + " numbers is " + avg);
        }
    }
}