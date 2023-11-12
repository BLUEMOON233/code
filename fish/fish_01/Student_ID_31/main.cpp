#include <iostream>
#include <vector>
using namespace std;

//题目1：
class CBox {
private:
    double length = 0;
    double width = 0;
    double height = 0;

public:
    CBox(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }

    double getVolume() {
        return length * width * height;
    }

    double getSurfaceArea() {
        return 2 * (length * width + length * height + width * height);
    }
};

//题目2：
class CScore {
protected:
    vector<string> studentIDs;
    vector<string> names;
    vector<double> scores;

public:
    void addScore(string studentID, string name, double score) {
        studentIDs.push_back(studentID);
        names.push_back(name);
        scores.push_back(score);
    }

    void calculate(double& minScore, double& maxScore, double& averageScore) {
        minScore = scores[0];
        maxScore = scores[0];
        double sum = scores[0];

        for (int i = 1; i < scores.size(); i++) {
            if (scores[i] < minScore) {
                minScore = scores[i];
            } //遍历比较，寻找最低成绩
            if (scores[i] > maxScore) {
                maxScore = scores[i];
            } //遍历比较，寻找最高成绩
            sum += scores[i]; //记录总成绩
        }

        averageScore = static_cast<double>(sum) / scores.size();
        //计算平均成绩
    }

    void outputResults() {
        if(studentIDs.empty()) {
            cout << "班级为空！" << endl;
            return;
        }
        double minScore, maxScore;
        double averageScore;
        calculate(minScore, maxScore, averageScore);

        std::cout << "最低成绩: " << minScore << std::endl;
        std::cout << "最高成绩: " << maxScore << std::endl;
        std::cout << "平均成绩: " << averageScore << std::endl;

        std::cout << "学生成绩单:" << std::endl;
        for (int i = 0; i < studentIDs.size(); i++) {
            std::cout << "学号: " << studentIDs[i] << ", 姓名: " << names[i] << ", 分数: " << scores[i] << std::endl;
        }
    }
};

//题目3：
class CScoreEx : public CScore {
public:
    int getPassCount() {
        int passCount = 0;
        for(int i = 0; i < scores.size(); i++) {
            if (scores[i] >= 60) {
                passCount++;
            }
        }
        return passCount;
    }

    int getFailCount() {
        int failCount = 0;
        for(int i = 0; i < scores.size(); i++) {
            if (scores[i] < 60) {
                failCount++;
            }
        }
        return failCount;
    }

    int getGreatCount() {
        int GreatCount = 0;
        for(int i = 0; i < scores.size(); i++) {
            if (scores[i] >= 90) {
                GreatCount++;
            }
        }
        return GreatCount;
    }

    void sortScores() {
        int n = scores.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (scores[j] < scores[j + 1]) {
                    swap(scores[j], scores[j + 1]);
                    swap(names[j], names[j + 1]);
                    swap(studentIDs[j], studentIDs[j + 1]);
                }
            }
        }
    }
};

int main() {
    system("chcp 65001"); //将控制台设置为utf-8格式避免输出中文乱码
    // CBox测试代码：
    cout << "\nCBox测试代码：" << endl;
    CBox box(3.0, 4.0, 5.0); //定义一个长宽高分别为3，4，5的立方体
    double volume = box.getVolume();
    double surfaceArea = box.getSurfaceArea();
    cout << "体积: " << volume << std::endl;
    cout << "表面积: " << surfaceArea << std::endl;
    cout << endl;

    // Cscore测试代码：
    cout << "\nCScore测试代码：" << endl;
    CScore score;
    // 输入学号、姓名和成绩
    score.addScore("001", "Alice", 90);
    score.addScore("002", "Bob", 85);
    score.addScore("003", "Charlie", 92);
    score.addScore("004", "David", 88);
    score.addScore("005", "Eve", 95);
    // 计算并输出结果
    score.outputResults();
    cout << endl;


    //CScoreEx测试代码：
    cout << "\nCScoreEx测试代码：" << endl;
    CScoreEx score_ex;
    // 输入学号、姓名和成绩
    score_ex.addScore("001", "Alice", 90);
    score_ex.addScore("002", "Bob", 85);
    score_ex.addScore("003", "Charlie", 92);
    score_ex.addScore("004", "David", 88);
    score_ex.addScore("005", "Eve", 95);

    // 排序计算并输出结果
    score_ex.sortScores(); //按照成绩对学生进行排序
    cout << "不及格人数：" << score_ex.getFailCount() << endl;
    cout << "及格人数：" << score_ex.getPassCount() << endl;
    cout << "优秀人数：" << score_ex.getGreatCount() << endl;
    score_ex.outputResults(); //输出成绩单
    return 0;
}
