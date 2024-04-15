public abstract class WinemakingProcess {
    final void makeWine() {
        buySeed();      //购买种子
        tillingAndSowing();     //耕种、播种
        chooseSprinkler();      //选择洒水器
        harvest();      //收获
        if(isUseCask()) {       //是否使用木桶
            makeWineWithCask();     //使用木桶酿酒
            return;
        }
        makeWineWithKeg();      //使用小桶酿酒
    }
    abstract void buySeed();

    void tillingAndSowing() {
        System.out.println("Step2: 播种、耕种");
    }

    abstract void chooseSprinkler();

    void harvest() {
        System.out.println("Step4: 收获农作物");
    }

    void makeWineWithKeg() {
        System.out.println("Step5: 使用小桶进行酿造");
    }

    void makeWineWithCask() {
        System.out.println("Step5: 使用木桶进行陈酿");
    }
    //钩子方法：
    boolean isUseCask() {
        return false;
    }
}

