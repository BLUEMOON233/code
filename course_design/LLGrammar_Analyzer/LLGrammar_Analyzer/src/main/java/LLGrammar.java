import java.util.*;

public class LLGrammar {
    String startSymbol;
    HashMap<String, ArrayList<ArrayList<String>>> expressions;
    HashSet<String> Vn; //非终结符
    HashSet<String> Vt; //终结符

    LLGrammar() {
        expressions = new HashMap<String, ArrayList<ArrayList<String>>>();
        Vn = new HashSet<>();
        Vt = new HashSet<>();
    }

    void setStartSymbol(String sym) {
        startSymbol = sym;
    }

    boolean input(String string) {
        string = string.replaceAll(" +", "");
        String[] key2values = string.split("->");
        if (key2values.length != 2)
            return false;
        if (key2values[0].isEmpty() || key2values[0].length() > 2)
            return false;
        if (key2values[0].length() == 2 && key2values[0].charAt(1) != '\'')
            return false;
        Vn.add(key2values[0]);
        if (!expressions.containsKey(key2values[0]))
            expressions.put(key2values[0], new ArrayList<>());
        String[] values = key2values[1].split("\\|");
        for (String value : values) {
            ArrayList<String> symList = new ArrayList<String>();
            for (int i = 0; i <= value.length() - 1; i++) {
                if (!LLGrammarTools.isCharLegal(value.charAt(i))) return false;
                if (i != value.length() - 1 && value.charAt(i + 1) == '\'') {
                    symList.add(value.substring(i, i + 2));
                    Vt.add(value.substring(i, i + 2));
                    i++;
                    continue;
                }
                symList.add(value.substring(i, i + 1));
                Vt.add(value.substring(i, i + 1));
            }
            expressions.get(key2values[0]).add(symList);
        }
        Vt.removeAll(Vn);
        return true;
    }

    ArrayList<Expression> getExpressions() {
        ArrayList<Expression> ret = new ArrayList<>();
        for (String nonTerminal : Vn) {
            for (ArrayList<String> right : expressions.get(nonTerminal)) {
                ret.add(new Expression(nonTerminal, right));
            }
        }
        return ret;
    }

    ArrayList<ArrayList<String>> getValue(String key) {
        if (!expressions.containsKey(key))
            return null;
        return expressions.get(key);
    }
}
