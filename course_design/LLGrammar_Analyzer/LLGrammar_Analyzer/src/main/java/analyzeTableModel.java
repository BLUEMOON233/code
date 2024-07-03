import javax.swing.table.AbstractTableModel;
import java.util.*;

public class analyzeTableModel extends AbstractTableModel {
    String[] columnNames;
    String[][] table;

    analyzeTableModel(NonRecursiveAnalyzer nonRecursiveAnalyzer) {
        HashMap<String, HashMap<String, Expression>> analyzeTable = nonRecursiveAnalyzer.getAnalyzeTable();
        LLGrammar llGrammar = nonRecursiveAnalyzer.getLLGrammar();
        String[] nonTerminals = llGrammar.Vn.toArray(new String[0]);
        HashSet<String> terminals = new HashSet<>(llGrammar.Vt);
        terminals.remove("ε");
        String[] headers = terminals.toArray(new String[0]);
        ArrayList<String> columns = new ArrayList<>();
        columns.add("\\");
        for (int i = 0; i <= headers.length - 1; i++) {
            columns.add(headers[i]);
        }
        columns.add("$");
        columnNames = columns.toArray(new String[0]);
        table = new String[nonTerminals.length][headers.length + 2];
        for (int i = 0; i <= nonTerminals.length - 1; i++) {
            String A = nonTerminals[i];
            HashMap<String, Expression> mapTer2Exp = analyzeTable.get(A);
            for (int j = 0; j <= headers.length - 1; j++) {
                if (mapTer2Exp.containsKey(headers[j])) {
                    Expression expression = mapTer2Exp.get(headers[j]);
                    System.out.printf("%s %s\n", A, expression);
                    if (table[i][j + 1] == null) table[i][j + 1] = expression.toString();
                    else table[i][j + 1] += "\n" + expression.toString();
                }
            }
            table[i][0] = A;
            if (mapTer2Exp.containsKey("$")) {
                Expression expression = mapTer2Exp.get("$");
                System.out.printf("%s %s\n", A, expression);
                if(table[i][headers.length + 1] == null) table[i][headers.length + 1] = expression.toString();
                else table[i][headers.length + 1] += "\n" + expression.toString();
            }
        }
    }

    analyzeTableModel(ArrayList<String> logStack, ArrayList<String> logInput, ArrayList<String> logAction) {
        columnNames = new String[]{"栈", "输入串", "动作"};
        table = new String[logStack.size()][3];
        for (int i = 0; i <= logStack.size() - 1; i++) {
            table[i][0] = logStack.get(i);
            table[i][1] = logInput.get(i);
            table[i][2] = logAction.get(i);
        }
    }

    @Override
    public int getRowCount() {
        return table.length;
    }

    @Override
    public int getColumnCount() {
        return columnNames.length;
    }

    @Override
    public String getColumnName(int column) {
        return columnNames[column];
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {
        return table[rowIndex][columnIndex];
    }
}
