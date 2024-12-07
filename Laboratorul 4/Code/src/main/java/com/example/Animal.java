package com.example;

public abstract class Animal extends EntityEcosystem {
    protected int speed;
    protected String food;

    public Animal(String name, double energy, int x, int y, float survivingRate, int speed, String food) {
        super(name, energy, x, y, survivingRate);
        this.speed = speed;
        this.food = food;
    }

    public String getFood() {
        return food;
    }

    public int getSpeed() {
        return speed;
    }

    public abstract void isEating();
    public abstract void isMoving();

    public void reduceEnergy(double amount) {
        this.energy = Math.max(0, this.energy - amount); 
    }

    public abstract void reproduce();
}
