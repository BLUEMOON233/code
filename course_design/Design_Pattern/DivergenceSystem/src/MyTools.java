import java.util.ArrayList;

public class MyTools {
    static String usList2String(ArrayList<UndivertedStudent> usList){
        StringBuilder sb = new StringBuilder();
        for(UndivertedStudent us : usList) {
            sb.append(us);
            sb.append('$');
        }
        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }
}