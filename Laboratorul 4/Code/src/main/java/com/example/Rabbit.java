package com.example;

public class Rabbit extends Herbivor {
    public Rabbit(String name, double energy, int x, int y, float survivingRate, int speed) {
        super(name, energy, x, y, survivingRate, speed, "plants");
    }

    @Override
    public void isEating() {
        super.isEating();
        this.energy += 15;
        System.out.println("The rabbit " + getName() + " is nibbling on some fresh plants and gaining extra energy.");
    }

    @Override
    public void isMoving() {
        super.isMoving();
        System.out.println("The rabbit hops quickly to position (" + getX() + ", " + getY() + ").");
    }
}
