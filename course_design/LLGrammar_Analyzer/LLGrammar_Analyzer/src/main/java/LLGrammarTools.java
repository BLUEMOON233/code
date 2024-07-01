import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;

public class LLGrammarTools {
    static HashSet<Character> operators = new HashSet<Character>(Arrays.asList('+', '-', '*', '/', '(', ')'));

    public static boolean isCharLegal(char val) {
        return Character.isLetter(val) || val == 'ε' || operators.contains(val);
    }

    public static ArrayList<String> inputSplit(String input){
        ArrayList<String> ret = new ArrayList<String>();
        input = input.replaceAll(" +", "");
        for (int i = 0; i <= input.length() - 1; i++) {
            if (!LLGrammarTools.isCharLegal(input.charAt(i))) return null;
            if (i != input.length() - 1 && input.charAt(i + 1) == '\'') {
                ret.add(input.substring(i, i + 2));
                i++;
                continue;
            }
            ret.add(input.substring(i, i + 1));
        }
        return ret;
    }
}
