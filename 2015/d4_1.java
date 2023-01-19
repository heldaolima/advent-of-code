import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

class d4_1 {
    public static void main(String[] args) throws NoSuchAlgorithmException {
        String input = args[0];         
        MessageDigest md = MessageDigest.getInstance("MD5");
        long curr = 0;

        while (true) {
            String key = String.format("%s%d", input, curr++);
            byte[] msgDigest = md.digest(key.getBytes());
            
            BigInteger no = new BigInteger(1, msgDigest);
            String hashtext = no.toString(16);

            while (hashtext.length() < 32) {
                hashtext = "0" + hashtext;
            }
            
            if (hashtext.startsWith("00000")) break;

            
        }
        
        System.out.println(curr-1);
    }

}