import com.formdev.flatlaf.themes.FlatMacLightLaf;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import javax.swing.text.AttributeSet;
import javax.swing.text.BadLocationException;
import javax.swing.text.PlainDocument;
/*
 * Created by JFormDesigner on Mon Jul 01 21:22:04 CST 2024
 */


/**
 * @author liuwy
 */
public class AnalyzerGUI extends JFrame {
    LLGrammar llGrammar;
    NonRecursiveAnalyzer nonRecursiveAnalyzer;

    public AnalyzerGUI() {
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        initComponents();
        TF_inputString.setDocument(new PlainDocument() {
            @Override
            public void insertString(int offs, String str, AttributeSet a) throws BadLocationException {
                if (isAllowedCharacters(str)) {
                    super.insertString(offs, str, a);
                }
            }

            @Override
            public void replace(int offset, int length, String text, AttributeSet attrs) throws BadLocationException {
                if (isAllowedCharacters(text)) {
                    super.replace(offset, length, text, attrs);
                }
            }

            private boolean isAllowedCharacters(String str) {
                HashSet<String> allowedChars = new HashSet<>(Arrays.asList("a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+", "-", "*", "/", "(", ")", "="));
                return allowedChars.contains(str);
            }
        });
    }

    private void BT_importGrammar(ActionEvent e) {
        String filePath = "";
        JFileChooser fileChooser = new JFileChooser();
        fileChooser.setCurrentDirectory(new File("."));
        int result = fileChooser.showOpenDialog(null);
        if (result == JFileChooser.APPROVE_OPTION) {
            filePath = fileChooser.getSelectedFile().getAbsolutePath();
        } else {
            return;
        }

        llGrammar = new LLGrammar();
        nonRecursiveAnalyzer = null;
        TA_Grammar.setText("");
        TA_first.setText("");
        TA_follow.setText("");
        TB_analyze.setModel(new DefaultTableModel());
        TB_process.setModel(new DefaultTableModel());
        CB_startSymbol.removeAllItems();
        try {
            BufferedReader in = new BufferedReader(new FileReader(filePath));
            String buffer;
            while ((buffer = in.readLine()) != null) {
                llGrammar.input(buffer);
            }
            ArrayList<Expression> expressions = llGrammar.getExpressions();
            for (Expression expression : expressions) {
                TA_Grammar.append(expression.toString() + "\n");
            }
            for (String symbol : llGrammar.Vn) {
                CB_startSymbol.addItem(symbol);
            }
            CB_startSymbol.addItem("");
            CB_startSymbol.setSelectedItem("");
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    private void BT_startSymbol(ActionEvent e) {
        if (llGrammar == null) {
            JOptionPane.showMessageDialog(null, "未导入文法", "错误", JOptionPane.WARNING_MESSAGE);
            return;
        }
        String val = CB_startSymbol.getSelectedItem().toString();
        if (!val.equals("")) llGrammar.startSymbol = CB_startSymbol.getSelectedItem().toString();
        else llGrammar.startSymbol = null;
        nonRecursiveAnalyzer = new NonRecursiveAnalyzer(llGrammar);
    }

    private void BT_disambiguation(ActionEvent e) {
        if (llGrammar == null || llGrammar.startSymbol == null) {
            JOptionPane.showMessageDialog(null, "文法未分配开始符号, 无法进行预测分析", "错误", JOptionPane.WARNING_MESSAGE);
            return;
        }
        if (!LLGrammarTools.delLeftFactor(llGrammar)) {
            JOptionPane.showMessageDialog(null, "未识别到左因子", "错误", JOptionPane.WARNING_MESSAGE);
            return;
        }
        TA_Grammar.setText("");
        CB_startSymbol.removeAllItems();
        CB_startSymbol.setSelectedItem(llGrammar.startSymbol);
        ArrayList<Expression> expressions = llGrammar.getExpressions();
        for (Expression expression : expressions) {
            TA_Grammar.append(expression.toString() + "\n");
        }
        for (String symbol : llGrammar.Vn) {
            CB_startSymbol.addItem(symbol);
        }
        CB_startSymbol.addItem("");
        if (llGrammar.startSymbol != null) CB_startSymbol.setSelectedItem(llGrammar.startSymbol);
        else CB_startSymbol.setSelectedItem("");
    }

    private void BT_eliminateLeftRecursion(ActionEvent e) {
        if (llGrammar == null || llGrammar.startSymbol == null) {
            JOptionPane.showMessageDialog(null, "文法未分配开始符号, 无法进行预测分析", "错误", JOptionPane.WARNING_MESSAGE);
            return;
        }
        if (!LLGrammarTools.delLeftRecursion(llGrammar)) {
            JOptionPane.showMessageDialog(null, "未识别到左递归", "错误", JOptionPane.WARNING_MESSAGE);
            return;
        }
        TA_Grammar.setText("");
        CB_startSymbol.removeAllItems();
        CB_startSymbol.setSelectedItem(llGrammar.startSymbol);
        ArrayList<Expression> expressions = llGrammar.getExpressions();
        for (Expression expression : expressions) {
            TA_Grammar.append(expression.toString() + "\n");
        }
        for (String symbol : llGrammar.Vn) {
            CB_startSymbol.addItem(symbol);
        }
        CB_startSymbol.addItem("");
        if (llGrammar.startSymbol != null) CB_startSymbol.setSelectedItem(llGrammar.startSymbol);
        else CB_startSymbol.setSelectedItem("");
    }

    private void BT_analyzeTable(ActionEvent e) {
        if (nonRecursiveAnalyzer == null) {
            JOptionPane.showMessageDialog(null, "文法未分配开始符号, 无法进行预测分析", "错误", JOptionPane.WARNING_MESSAGE);
            return;
        }
        if (nonRecursiveAnalyzer.First.isEmpty() || nonRecursiveAnalyzer.First.isEmpty()) {
            JOptionPane.showMessageDialog(null, "First集或Follow集为空", "分析失败", JOptionPane.WARNING_MESSAGE);
            return;
        }
        analyzeTableModel tableModel = new analyzeTableModel(nonRecursiveAnalyzer);
        TB_analyze.setModel(tableModel);
    }

    private void BT_analyze(ActionEvent e) {
        if (nonRecursiveAnalyzer == null) {
            JOptionPane.showMessageDialog(null, "文法未分配开始符号, 无法进行非递归分析", "错误", JOptionPane.WARNING_MESSAGE);
            return;
        }
        if (nonRecursiveAnalyzer.First.isEmpty() || nonRecursiveAnalyzer.First.isEmpty()) {
            JOptionPane.showMessageDialog(null, "First集或Follow集为空", "分析失败", JOptionPane.WARNING_MESSAGE);
            return;
        }
        analyzeTableModel tableModel = nonRecursiveAnalyzer.Analyze(TF_inputString.getText(), nonRecursiveAnalyzer.getAnalyzeTable());
        if (!tableModel.getValueAt(tableModel.getRowCount() - 1, 0).equals("")) {
            JOptionPane.showMessageDialog(null, "输入字符串不被该文法所识别", "匹配失败", JOptionPane.WARNING_MESSAGE);
        }
        TB_process.setModel(tableModel);
    }

    private void BT_firstAndFollow(ActionEvent e) {
        if (llGrammar == null || llGrammar.startSymbol == null) {
            JOptionPane.showMessageDialog(null, "文法未分配开始符号, 无法求出Follow集", "错误", JOptionPane.WARNING_MESSAGE);
            return;
        }
        TA_first.setText("");
        TA_follow.setText("");
        nonRecursiveAnalyzer.getFirstSet();
        for (String nonTerminal : llGrammar.Vn) {
            HashSet<String> first = nonRecursiveAnalyzer.First.get(nonTerminal);
            StringBuilder sb = new StringBuilder();
            sb.append(String.format("FIRST(%s): {", nonTerminal));
            for (String symbol : first) {
                sb.append(symbol);
                sb.append(", ");
            }
            sb.delete(sb.length() - 2, sb.length());
            sb.append("}\n");
            TA_first.append(sb.toString());
        }
        nonRecursiveAnalyzer.getFollowSet();
        for (String nonTerminal : llGrammar.Vn) {
            HashSet<String> follow = nonRecursiveAnalyzer.Follow.get(nonTerminal);
            StringBuilder sb = new StringBuilder();
            sb.append(String.format("FOLLOW(%s): {", nonTerminal));
            for (String symbol : follow) {
                sb.append(symbol);
                sb.append(", ");
            }
            sb.delete(sb.length() - 2, sb.length());
            sb.append("}\n");
            TA_follow.append(sb.toString());
        }
    }


    private void initComponents() {
        // JFormDesigner - Component initialization - DO NOT MODIFY  //GEN-BEGIN:initComponents  @formatter:off
        BT_importGrammar = new JButton();
        scrollPane1 = new JScrollPane();
        TA_Grammar = new JTextArea();
        label1 = new JLabel();
        BT_disambiguation = new JButton();
        BT_eliminateLeftRecursion = new JButton();
        BT_startSymbol = new JButton();
        label2 = new JLabel();
        CB_startSymbol = new JComboBox();
        BT_analyze = new JButton();
        BT_analyzeTable = new JButton();
        scrollPane2 = new JScrollPane();
        TB_analyze = new JTable();
        scrollPane3 = new JScrollPane();
        TB_process = new JTable();
        scrollPane4 = new JScrollPane();
        TA_first = new JTextArea();
        BT_firstAndFollow = new JButton();
        scrollPane5 = new JScrollPane();
        TA_follow = new JTextArea();
        TF_inputString = new JFormattedTextField();
        label3 = new JLabel();

        //======== this ========
        setMaximumSize(new Dimension(1280, 720));
        setMinimumSize(new Dimension(1280, 720));
        setPreferredSize(new Dimension(1280, 720));
        setResizable(false);
        setTitle("LLGrammarAnalyzer");
        setModalExclusionType(Dialog.ModalExclusionType.APPLICATION_EXCLUDE);
        setName("frame0");
        var contentPane = getContentPane();
        contentPane.setLayout(null);

        //---- BT_importGrammar ----
        BT_importGrammar.setText("\u5bfc\u5165\u6587\u6cd5");
        BT_importGrammar.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 22));
        BT_importGrammar.addActionListener(e -> BT_importGrammar(e));
        contentPane.add(BT_importGrammar);
        BT_importGrammar.setBounds(20, 15, 155, 55);

        //======== scrollPane1 ========
        {

            //---- TA_Grammar ----
            TA_Grammar.setFont(new Font("Consolas", Font.PLAIN, 24));
            TA_Grammar.setEditable(false);
            scrollPane1.setViewportView(TA_Grammar);
        }
        contentPane.add(scrollPane1);
        scrollPane1.setBounds(20, 115, 230, 540);

        //---- label1 ----
        label1.setText("\u5f53\u524d\u6587\u6cd5");
        label1.setFont(new Font("\u5e7c\u5706", Font.BOLD, 20));
        contentPane.add(label1);
        label1.setBounds(25, 80, 95, 30);

        //---- BT_disambiguation ----
        BT_disambiguation.setText("\u63d0\u53d6\u5de6\u56e0\u5b50");
        BT_disambiguation.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 22));
        BT_disambiguation.addActionListener(e -> BT_disambiguation(e));
        contentPane.add(BT_disambiguation);
        BT_disambiguation.setBounds(345, 15, 155, 55);

        //---- BT_eliminateLeftRecursion ----
        BT_eliminateLeftRecursion.setText("\u6d88\u9664\u5de6\u9012\u5f52");
        BT_eliminateLeftRecursion.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 22));
        BT_eliminateLeftRecursion.addActionListener(e -> BT_eliminateLeftRecursion(e));
        contentPane.add(BT_eliminateLeftRecursion);
        BT_eliminateLeftRecursion.setBounds(510, 15, 155, 55);

        //---- BT_startSymbol ----
        BT_startSymbol.setText("\u5f00\u59cb\u7b26\u53f7");
        BT_startSymbol.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 22));
        BT_startSymbol.addActionListener(e -> BT_startSymbol(e));
        contentPane.add(BT_startSymbol);
        BT_startSymbol.setBounds(180, 15, 155, 55);

        //---- label2 ----
        label2.setText("\u9009\u62e9\u5f00\u59cb\u7b26\u53f7");
        label2.setFont(new Font("\u5e7c\u5706", Font.BOLD, 20));
        contentPane.add(label2);
        label2.setBounds(120, 80, 130, 30);

        //---- CB_startSymbol ----
        CB_startSymbol.setFont(new Font("Consolas", Font.BOLD, 20));
        contentPane.add(CB_startSymbol);
        CB_startSymbol.setBounds(255, 75, 80, 40);

        //---- BT_analyze ----
        BT_analyze.setText("\u975e\u9012\u5f52\u5206\u6790");
        BT_analyze.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 22));
        BT_analyze.addActionListener(e -> BT_analyze(e));
        contentPane.add(BT_analyze);
        BT_analyze.setBounds(1100, 15, 155, 55);

        //---- BT_analyzeTable ----
        BT_analyzeTable.setText("\u6784\u9020\u5206\u6790\u8868");
        BT_analyzeTable.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 22));
        BT_analyzeTable.addActionListener(e -> BT_analyzeTable(e));
        contentPane.add(BT_analyzeTable);
        BT_analyzeTable.setBounds(940, 15, 155, 55);

        //======== scrollPane2 ========
        {

            //---- TB_analyze ----
            TB_analyze.setShowHorizontalLines(true);
            TB_analyze.setShowVerticalLines(true);
            TB_analyze.setFont(new Font("Consolas", Font.PLAIN, 20));
            scrollPane2.setViewportView(TB_analyze);
        }
        contentPane.add(scrollPane2);
        scrollPane2.setBounds(260, 360, 665, 290);

        //======== scrollPane3 ========
        {

            //---- TB_process ----
            TB_process.setFont(new Font("\u5fae\u8f6f\u96c5\u9ed1", Font.PLAIN, 14));
            scrollPane3.setViewportView(TB_process);
        }
        contentPane.add(scrollPane3);
        scrollPane3.setBounds(945, 80, 305, 575);

        //======== scrollPane4 ========
        {

            //---- TA_first ----
            TA_first.setFont(new Font("Consolas", Font.PLAIN, 20));
            TA_first.setEditable(false);
            scrollPane4.setViewportView(TA_first);
        }
        contentPane.add(scrollPane4);
        scrollPane4.setBounds(260, 120, 330, 230);

        //---- BT_firstAndFollow ----
        BT_firstAndFollow.setText("\u6c42First\u96c6&Follow\u96c6");
        BT_firstAndFollow.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 24));
        BT_firstAndFollow.addActionListener(e -> BT_firstAndFollow(e));
        contentPane.add(BT_firstAndFollow);
        BT_firstAndFollow.setBounds(670, 15, 260, 55);

        //======== scrollPane5 ========
        {

            //---- TA_follow ----
            TA_follow.setFont(new Font("Consolas", Font.PLAIN, 20));
            TA_follow.setEditable(false);
            scrollPane5.setViewportView(TA_follow);
        }
        contentPane.add(scrollPane5);
        scrollPane5.setBounds(595, 125, 330, 225);

        //---- TF_inputString ----
        TF_inputString.setFont(new Font("Consolas", Font.PLAIN, 22));
        contentPane.add(TF_inputString);
        TF_inputString.setBounds(420, 75, 500, 40);

        //---- label3 ----
        label3.setText("\u8f93\u5165\u4e32");
        label3.setFont(new Font("\u5e7c\u5706", Font.BOLD, 20));
        contentPane.add(label3);
        label3.setBounds(345, 80, 70, 30);

        contentPane.setPreferredSize(new Dimension(1025, 575));
        setLocationRelativeTo(getOwner());
        // JFormDesigner - End of component initialization  //GEN-END:initComponents  @formatter:on
    }

    // JFormDesigner - Variables declaration - DO NOT MODIFY  //GEN-BEGIN:variables  @formatter:off
    private JButton BT_importGrammar;
    private JScrollPane scrollPane1;
    private JTextArea TA_Grammar;
    private JLabel label1;
    private JButton BT_disambiguation;
    private JButton BT_eliminateLeftRecursion;
    private JButton BT_startSymbol;
    private JLabel label2;
    private JComboBox CB_startSymbol;
    private JButton BT_analyze;
    private JButton BT_analyzeTable;
    private JScrollPane scrollPane2;
    private JTable TB_analyze;
    private JScrollPane scrollPane3;
    private JTable TB_process;
    private JScrollPane scrollPane4;
    private JTextArea TA_first;
    private JButton BT_firstAndFollow;
    private JScrollPane scrollPane5;
    private JTextArea TA_follow;
    private JFormattedTextField TF_inputString;
    private JLabel label3;
    // JFormDesigner - End of variables declaration  //GEN-END:variables  @formatter:on

    public static void main(String[] args) {
        FlatMacLightLaf.setup();
        new AnalyzerGUI().setVisible(true);
    }
}
