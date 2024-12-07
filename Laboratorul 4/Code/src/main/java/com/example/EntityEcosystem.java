package com.example;

public abstract class EntityEcosystem {
    protected String name;
    protected double energy;
    protected int x, y;
    protected float survivingRate;
    public  EntityEcosystem(String name, double energy, int x, int y, float survivingRate){
        this.name = name;
        this.energy = energy;
        this.x = x;
        this.y = y;
        this.survivingRate = survivingRate;
    }
    public String getName(){
        return name;
    }
    public double getEnergy(){
        return energy;
    }
    public int getX(){
        return x;
    }
    public int getY(){
        return y;
    }
    public float getSurvivingRate(){
        return survivingRate;
    }
    public abstract void act();
    public void reduceEnergy(double amount) {
        this.energy = Math.max(0, this.energy - amount); 
    }
    
    public boolean isDead() {
        return false; 
    }
    
}

