import java.util.ArrayList;
public class UserInfo {
    private final ArrayList<Node> userNodeList;

    public UserInfo() {
        userNodeList = new ArrayList<>();
    }
    public UserInfo(ArrayList<Node> userNodeList) {
        this.userNodeList = userNodeList;
    }
    public void addUser(Node node){
        if (this.searchUserByName(node.username) == null)
            userNodeList.add(node);
    }
    public void deleteUser(Node node){
        userNodeList.remove(searchUserByName(node.username));
    }
    public void deleteUser(String username){
        userNodeList.remove(searchUserByName(username));
    }
    public int getCount(){
        return userNodeList.size();
    }
    public Node searchUserByName(String username){
        for (Node n:userNodeList){
            if (n.username.equals(username))
                return n;
        }
        return null;
    }
    public Node searchUserByIndex(int index){
        if (index <userNodeList.size())
            return userNodeList.get(index);
        return null;
    }

    public void setOnlineStatus(boolean b){
        for (Node node:userNodeList)
            node.setOnlineInfo(b);
    }
    public void setOfflineStatus(boolean b){
        for (Node node:userNodeList)
            node.setOfflineInfo(b);
    }
    @Override
    public String toString() {
        StringBuilder userInfo = new StringBuilder();
        for (Node n:userNodeList){
            userInfo.append(n.toString());
            userInfo.append("$");
        }
        return String.valueOf(userInfo.deleteCharAt(userInfo.length()-1));
    }
}
