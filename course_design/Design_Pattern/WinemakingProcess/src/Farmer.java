class Rhubarb extends WinemakingProcess {
    @Override
    void buySeed() {
        System.out.println("Step1: 购买大黄种子");
    }

    @Override
    void chooseSprinkler() {
        System.out.println("Step3: 使用普通洒水器");
    }
}

class Starfruit extends WinemakingProcess {
    @Override
    void buySeed() {
        System.out.println("Step1: 购买杨桃种子");
    }

    @Override
    void chooseSprinkler() {
        System.out.println("Step3: 选择优质洒水器");
    }

    @Override
    boolean isUseCask() {
        //采用木桶陈酿
        return true;
    }
}

class Pumpkin extends WinemakingProcess {
    @Override
    void buySeed() {
        System.out.println("Step1: 购买南瓜种子");
    }

    @Override
    void chooseSprinkler() {
        System.out.println("Step3: 使用铱制洒水器");
    }
}


public class Farmer {
    public static void main(String[] args) {
        System.out.println("------制作大黄果酒------");
        WinemakingProcess rhubarb = new Rhubarb();
        rhubarb.makeWine();
        System.out.println("----------------------");

        System.out.println("----制作陈酿杨桃果酒-----");
        WinemakingProcess starfruit = new Starfruit();
        starfruit.makeWine();
        System.out.println("----------------------");

        System.out.println("------制作南瓜果汁------");
        WinemakingProcess pumpkin = new Pumpkin();
        pumpkin.makeWine();
        System.out.println("----------------------");
    }
}
