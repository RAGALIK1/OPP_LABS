package com.example;

public class Herbivor extends Animal implements Interaction {

    public Herbivor(String name, double energy, int x, int y, float survivingRate, int speed, String food) {
        super(name, energy, x, y, survivingRate, speed, food);
    }

    @Override
    public void act() {
        System.out.println(getName() + " is acting as a herbivore.");
    }

    @Override
    public void isEating() {
        energy += 25;
        System.out.println(getName() + " is eating " + getFood() + ".");
    }

    @Override
    public void isMoving() {
        x += speed;
        System.out.println(getName() + " moved to position (" + x + ", " + y + ").");
    }

    @Override
    public void attack(Animal prada) {
        prada.reduceEnergy(10);
    }

    @Override
    public void reproduce() {
        System.out.println(getName() + " reproduced.");
    }
}
