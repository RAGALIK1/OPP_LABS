package com.example;

import java.util.Random;

import com.example.Ecosystem;
import com.example.EntityEcosystem;
import com.example.Herbivor;
import com.example.Carnivore;
import com.example.Omnivore;

public class Main {
    public static void main(String[] args) {

        Ecosystem ecosystem = new Ecosystem();
        

        EntityEcosystem herbivor = new Herbivor("Herbivor 1", 100, 0, 0, 0.8f, 1, "herb");
        EntityEcosystem carnivor = new Carnivore("Carnivor 1", 100, 1, 1, 0.7f, 2, "meat");
        EntityEcosystem omnivor = new Omnivore("Omnivor 1", 100, 2, 2, 0.75f, 3, "mixed");

        ecosystem.addEntity(herbivor);
        ecosystem.addEntity(carnivor);
        ecosystem.addEntity(omnivor);
        

        System.out.println("Începe simularea ecosistemului...");
        ecosystem.simulate(10); 

        ecosystem.displayEcosystem();
    }
}
