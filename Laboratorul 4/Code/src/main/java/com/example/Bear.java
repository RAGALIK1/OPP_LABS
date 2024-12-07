package com.example;

public class Bear extends Omnivore{
    public Bear(String name, double energy,  int x, int y,  float survivingRate, int speed) {
        super(name, energy,  x, y, survivingRate, speed, "plants and meat");
    }

    @Override
    public void isEating() {
        super.isEating();
        System.out.println("The bear " + getName() + " munches on some berries and meat.");
    }

    @Override
    public void isMoving() {
        super.isMoving();
        System.out.println("The bear lumbers to position (" + getX() + ", " + getY() + ").");
    }
}
