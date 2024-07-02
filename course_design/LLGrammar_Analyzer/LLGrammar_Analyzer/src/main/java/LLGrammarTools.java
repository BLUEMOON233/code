import java.util.*;

public class LLGrammarTools {
    static HashSet<Character> operators = new HashSet<Character>(Arrays.asList('+', '-', '*', '/', '(', ')', '='));

    public static boolean isCharLegal(char val) {
        return Character.isLetter(val) || val == 'ε' || operators.contains(val);
    }

    public static ArrayList<String> inputSplit(String input) {
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

    private static String getNewNonTerminal(LLGrammar llGrammar) {
        for (char c = 'A'; c <= 'Z'; c++) {
            if (!llGrammar.Vn.contains(String.valueOf(c))) return String.valueOf(c);
        }
        return null;
    }

    private static boolean checkLeftFactor(LLGrammar llGrammar) {
        for (String nonTerminal : llGrammar.Vn) {
            HashSet<String> set = new HashSet<>();
            for (ArrayList<String> right : llGrammar.expressions.get(nonTerminal)) {
                if (set.contains(right.get(0))) {
                    return true;
                }
                set.add(right.get(0));
            }
        }
        return false;
    }

    private static ArrayList<String> getLeftFactor(ArrayList<ArrayList<String>> rights) {
        for (int i = 0; i <= rights.size() - 1; i++) {
            for (int j = i + 1; j <= rights.size() - 1; j++) {
                int pos = 0;
                ArrayList<String> alpha = rights.get(i);
                ArrayList<String> beta = rights.get(j);
                while (pos < alpha.size() && pos < beta.size() && alpha.get(pos).equals(beta.get(pos))) pos++;
                if (pos != 0) {
                    ArrayList<String> ret = new ArrayList<>();
                    for (int k = 0; k < pos; k++)
                        ret.add(alpha.get(k));
                    return ret;
                }
            }
        }
        return null;
    }

    public static boolean delLeftFactor(LLGrammar llGrammar) {
        if (!checkLeftFactor(llGrammar)) return false;
        while (checkLeftFactor(llGrammar)) {
            for (String nonTerminal : llGrammar.Vn) {
                ArrayList<ArrayList<String>> rights = llGrammar.expressions.get(nonTerminal);
                ArrayList<String> leftFactor;
                if ((leftFactor = getLeftFactor(rights)) != null) {
                    String newNonTerminal = getNewNonTerminal(llGrammar);
                    llGrammar.expressions.put(newNonTerminal, new ArrayList<ArrayList<String>>());
                    Iterator<ArrayList<String>> iterator = rights.iterator();
                    while (iterator.hasNext()) {
                        ArrayList<String> right = iterator.next();
                        boolean flag = true;
                        for (int j = 0; j < leftFactor.size(); j++) {
                            if (!leftFactor.get(j).equals(right.get(j))) {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) {
                            ArrayList<String> newRight = new ArrayList<>();
                            for (int j = leftFactor.size(); j < right.size(); j++)
                                newRight.add(right.get(j));
                            llGrammar.expressions.get(newNonTerminal).add(newRight);
                            iterator.remove();
                        }
                    }
                    ArrayList<String> newExpression = new ArrayList<>(leftFactor);
                    newExpression.add(newNonTerminal);
                    llGrammar.expressions.get(nonTerminal).add(newExpression);
                    break;
                }
            }
            llGrammar.calVnVt();
        }
        return true;
    }

    private static boolean checkDirectLeftRecursion(LLGrammar llGrammar) {
        for (String nonTerminal : llGrammar.Vn) {
            for (ArrayList<String> right : llGrammar.expressions.get(nonTerminal)) {
                if (right.get(0).equals(nonTerminal)) {
                    return true;
                }
            }
        }
        return false;
    }

    private static String checkIndirectLeftRecursion(LLGrammar llGrammar) {
        HashSet<String> set = new HashSet<>();
        return (dfs(set, llGrammar.startSymbol, llGrammar));
    }

    private static String dfs(HashSet<String> set, String cur, LLGrammar llGrammar) {
        if (set.contains(cur)) return cur;
        set.add(cur);
        for (ArrayList<String> right : llGrammar.expressions.get(cur)) {
            if (llGrammar.Vn.contains(right.get(0))) {
                String flag = dfs(set, right.get(0), llGrammar);
                if (flag != null) return flag;
            }
        }
        return null;
    }

    public static boolean delLeftRecursion(LLGrammar llGrammar) {
        String flag = checkIndirectLeftRecursion(llGrammar);
        if (flag == null && !checkDirectLeftRecursion(llGrammar)) return false;
        delDirectLeftRecursion(llGrammar);
        flag = checkIndirectLeftRecursion(llGrammar);
//        System.out.println(flag);
        while (flag != null) {
            for (String nonTerminal : llGrammar.Vn) {
                if (nonTerminal.equals(flag)) continue;
                ArrayList<ArrayList<String>> rights = llGrammar.expressions.get(nonTerminal);
                Iterator<ArrayList<String>> iterator = rights.iterator();
                ArrayList<ArrayList<String>> newRights = new ArrayList<>();
                while (iterator.hasNext()) {
                    ArrayList<String> right = iterator.next();
                    if (right.get(0).equals(flag)) {
                        right.remove(0);
                        for (ArrayList<String> flagRight : llGrammar.expressions.get(flag)) {
                            ArrayList<String> newRight = new ArrayList<>(right);
                            for (int i = flagRight.size() - 1; i >= 0; i--) {
                                newRight.add(0, flagRight.get(i));
                            }
                            newRights.add(newRight);
                        }
                        iterator.remove();
                    }
                }
                rights.addAll(newRights);
            }
            delDirectLeftRecursion(llGrammar);
            flag = checkIndirectLeftRecursion(llGrammar);
        }
        return true;
    }

    private static void delDirectLeftRecursion(LLGrammar llGrammar) {
        if (!checkDirectLeftRecursion(llGrammar)) return;
        while (checkDirectLeftRecursion(llGrammar)) {
            for (String nonTerminal : llGrammar.Vn) {
                boolean flag = false;
                ArrayList<ArrayList<String>> rights = llGrammar.expressions.get(nonTerminal);
                for (ArrayList<String> right : rights) {
                    if (right.get(0).equals(nonTerminal)) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) continue;
                String newNonTerminal = nonTerminal + "'";
                llGrammar.expressions.put(newNonTerminal, new ArrayList<ArrayList<String>>());
                Iterator<ArrayList<String>> iterator = rights.iterator();
                while (iterator.hasNext()) {
                    ArrayList<String> right = iterator.next();
                    if (right.get(0).equals(nonTerminal)) {
                        right.remove(0);
                        right.add(newNonTerminal);
                        llGrammar.expressions.get(newNonTerminal).add(right);
                        iterator.remove();
                    } else {
                        if (right.get(0).equals("ε")) right.remove(0);
                        right.add(newNonTerminal);
                    }
                }
                ArrayList<String> epsilon = new ArrayList<>();
                epsilon.add("ε");
                llGrammar.expressions.get(newNonTerminal).add(epsilon);
                break;
            }
            llGrammar.calVnVt();
        }
    }

}
