import java.util.ArrayList;

public class Expression {
    public String left;
    public ArrayList<String> right;
    Expression(String left, ArrayList<String> right) {
        this.left = left;
        this.right = right;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(left);
        sb.append("->");
        right.forEach(sb::append);
        return sb.toString();
    }
}
