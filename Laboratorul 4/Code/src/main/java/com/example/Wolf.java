package com.example;

public class Wolf extends Carnivore{
    public Wolf(String name, double energy, int x, int y, float survivingRate, int speed) {
        super(name,  energy, x, y, survivingRate, speed, "meat");
    }

    @Override
    public void isEating() {
        super.isEating();
        System.out.println("The wolf " + getName() + " devours its prey.");
    }

    @Override
    public void isMoving() {
        super.isMoving();
        System.out.println("The wolf prowls silently to position (" + getX() + ", " + getY() + ").");
    }
}
