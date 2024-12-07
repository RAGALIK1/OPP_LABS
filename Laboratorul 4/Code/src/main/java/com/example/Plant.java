package com.example;

public class Plant extends EntityEcosystem {
    public Plant(String name, double energy, int x, int y, float survivingRate){
        super(name, energy, x, y, survivingRate);
    }
    @Override
    public void act(){
        energy += 5;
        System.out.println("The plant " + getName() + " grew and gained" + getEnergy() + " energy.");
    }
}
