import java.util.*;

public class NonRecursiveAnalyzer {
    HashMap<String, HashSet<String>> Follow;
    HashMap<String, HashSet<String>> First;
    LLGrammar llGrammar;

    NonRecursiveAnalyzer(LLGrammar llGrammar) {
        this.llGrammar = llGrammar;
        Follow = new HashMap<String, HashSet<String>>();
        First = new HashMap<String, HashSet<String>>();
    }

    LLGrammar getLLGrammar() {
        return llGrammar;
    }

    void getFirstSet() {
        for (String nonTerminal : llGrammar.Vn) {
            getFirstSet(nonTerminal);
            Follow.put(nonTerminal, new HashSet<String>());
        }
    }

    HashSet<String> getFirstSet(String nonTerminal) {
        if (First.containsKey(nonTerminal)) {
            return new HashSet<>(First.get(nonTerminal));
        }
        HashSet<String> ret = new HashSet<String>();
        for (ArrayList<String> right : llGrammar.getValue(nonTerminal)) {
            for (int i = 0; i <= right.size() - 1; i++) {
                String val = right.get(i);
                if (llGrammar.Vt.contains(val)) {
                    ret.add(val);
                    break;
                }
                HashSet<String> res = getFirstSet(val);
                boolean flag = res.remove("ε");
                ret.addAll(res);
                if (!flag) break;
                if (i == right.size() - 1) ret.add("ε");
            }
        }
        First.put(nonTerminal, ret);
        return new HashSet<>(ret);
    }

    void getFollowSet() {
        Follow.get(llGrammar.startSymbol).add("$");
        boolean flag = true;
        while (flag) {
            flag = false;
            for (String nonTerminal : llGrammar.Vn) {
                HashSet<String> follow = Follow.get(nonTerminal);
                for (ArrayList<String> right : llGrammar.getValue(nonTerminal)) {
                    int len = right.size();
                    for (int i = 0; i <= len - 2; i++) {
                        String val = right.get(i);
                        if (llGrammar.Vt.contains(val))
                            continue;
                        String beh = right.get(i + 1);
                        if (llGrammar.Vt.contains(beh)) {
                            flag |= Follow.get(val).add(beh);
                        } else {
                            HashSet<String> first = new HashSet<>(First.get(beh));
                            first.remove("ε");
                            flag |= Follow.get(val).addAll(first);
                        }
                    }
                    for (int i = len - 1; i >= 0; i--) {
                        String val = right.get(i);
                        if (llGrammar.Vt.contains(val)) {
                            break;
                        }
                        flag |= Follow.get(val).addAll(follow);
                        if (!First.get(val).contains("ε")) break;
                    }
                }
            }
        }
    }

    HashMap<String, HashMap<String, Expression>> getAnalyzeTable() {
        String[] nonTerminal = llGrammar.Vn.toArray(new String[0]);
        HashMap<String, HashMap<String, Expression>> analyzeTable = new HashMap<>();

        for (String A : nonTerminal) {
            HashMap<String, Expression> mapTer2Exp = new HashMap<>();
            for (ArrayList<String> right : llGrammar.getValue(A)) {
                Expression expression = new Expression(A, right);
                String a = right.get(0);
                HashSet<String> terminals = new HashSet<>();
                if (llGrammar.Vt.contains(a)) {
                    terminals.add(a);
                } else {
                    terminals.addAll(First.get(a));
                }
                if (terminals.contains("ε")) {
                    terminals.remove("ε");
                    terminals.addAll(Follow.get(A));
                }
                for (String val : terminals) {
                    mapTer2Exp.put(val, expression);
                }
            }
            analyzeTable.put(A, mapTer2Exp);
        }
        return analyzeTable;
    }

    analyzeTableModel Analyze(String inputString, HashMap<String, HashMap<String, Expression>> table) {
        ArrayList<String> symbolList = LLGrammarTools.inputSplit(inputString);
        if (symbolList == null)
            return null;
        ArrayDeque<String> input = new ArrayDeque<>(symbolList);
        input.offer("$");
        Stack<String> stack = new Stack<>();
        stack.add("$");
        stack.add(llGrammar.startSymbol);
        ArrayList<String> logStack = new ArrayList<>();
        ArrayList<String> logInput = new ArrayList<>();
        ArrayList<String> logAction = new ArrayList<>();
        logStack.add("$" + llGrammar.startSymbol);
        {
            StringBuilder sb = new StringBuilder();
            input.forEach(sb::append);
            logInput.add(sb.toString());
        }
        logAction.add("");
        while (!stack.isEmpty()) {
            if (stack.peek().equals(input.peek())) {
                String token = input.poll();
                stack.pop();
                logAction.add("匹配" + token);
            } else {
                HashMap<String, Expression> mapTer2Exp = table.get(stack.pop());
                Expression expression = mapTer2Exp.get(input.peek());
                for (int i = expression.right.size() - 1; i >= 0; i--) {
                    stack.add(expression.right.get(i));
                }
                while (stack.peek().equals("ε")) stack.pop();
                logAction.add("输出" + expression.toString());
            }
            StringBuilder sb = new StringBuilder();
            stack.forEach(sb::append);
            logStack.add(sb.toString());
            sb = new StringBuilder();
            input.forEach(sb::append);
            logInput.add(sb.toString());
        }
//        logStack.forEach(System.out::println);
//        logInput.forEach(System.out::println);
//        logAction.forEach(System.out::println);
        return new analyzeTableModel(logStack, logInput, logAction);
    }

    public static void main(String[] args) {
        LLGrammar llGrammar = new LLGrammar();
        llGrammar.input("E->TE'");
        llGrammar.input("E'->+TE'|ε");
        llGrammar.input("T->FT'");
        llGrammar.input("T'->*FT'|ε");
        llGrammar.input("F->(E)|a");
        llGrammar.setStartSymbol("E");
        System.out.println(llGrammar.Vt);
        System.out.println(llGrammar.Vn);
        NonRecursiveAnalyzer analyzer = new NonRecursiveAnalyzer(llGrammar);
        for (String val : llGrammar.Vn) {
            System.out.printf("First Set of %s: ", val);
            System.out.println(analyzer.First.get(val));
        }
        for (String val : llGrammar.Vn) {
            System.out.printf("Follow Set of %s: ", val);
            System.out.println(analyzer.Follow.get(val));
        }

        analyzer.Analyze("a * a + a", analyzer.getAnalyzeTable());

//        LLGrammar llGrammar = new LLGrammar();
//        llGrammar.input("E->TE'");
//        llGrammar.input("E'->+TE'|ε");
//        llGrammar.input("T->FT'");
//        llGrammar.input("T'->T|ε");
//        llGrammar.input("F->PF'");
//        llGrammar.input("F'->*F'|ε");
//        llGrammar.input("P->(E)|a|b|d");
//        llGrammar.setStartSymbol("E");
//        System.out.println(llGrammar.Vt);
//        System.out.println(llGrammar.Vn);
//        NonRecursiveAnalyzer NonRecursiveAnalyzer = new NonRecursiveAnalyzer(llGrammar);
//        for (String val : llGrammar.Vn) {
//            System.out.printf("First Set of %s: ", val);
//            System.out.println(NonRecursiveAnalyzer.First.get(val));
//        }
//        for (String val : llGrammar.Vn) {
//            System.out.printf("Follow Set of %s: ", val);
//            System.out.println(NonRecursiveAnalyzer.Follow.get(val));
//        }
    }

}
