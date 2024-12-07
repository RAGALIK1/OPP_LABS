package com.example;

public class Carnivore extends Animal implements Interaction {

    public Carnivore(String name, double energy, int x, int y, float survivingRate, int speed, String food) {
        super(name, energy, x, y, survivingRate, speed, food);
    }

    @Override
    public void act() {
        System.out.println(getName() + " is acting as a carnivore.");
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
        prada.reduceEnergy(50);
        System.out.println(getName() + " attacked " + prada.getName() + ".");
    }

    @Override
    public void reproduce() {
        System.out.println(getName() + " reproduced.");
    }
}
