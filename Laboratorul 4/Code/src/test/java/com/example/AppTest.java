package com.example;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class AppTest {

    private Ecosystem ecosystem;
    private Animal herbivor;
    private Animal carnivor;
    private Animal omnivor;

    @BeforeEach
    public void setUp() {
        ecosystem = new Ecosystem();
        herbivor = new Herbivor("Herbivor 1", 100, 0, 0, 0.8f, 1, "herb");
        carnivor = new Carnivore("Carnivor 1", 100, 1, 1, 0.7f, 2, "meat");
        omnivor = new Omnivore("Omnivor 1", 100, 2, 2, 0.75f, 3, "mixed");
    }



    @Test
    public void testEnergyReduction() {
        double initialEnergy = herbivor.getEnergy();
        herbivor.reduceEnergy(20);
        assertEquals(initialEnergy - 20, herbivor.getEnergy(), "Energy should decrease by the specified amount.");
    }

    @Test
    public void testIsEating() {
        herbivor.isEating();
        assertEquals(125, herbivor.getEnergy(), "Energy should increase by 25 after eating.");
    }

    @Test
    public void testIsMoving() {
        int initialX = carnivor.getX();
        carnivor.isMoving();
        assertEquals(initialX + carnivor.getSpeed(), carnivor.getX(), "Carnivor should have moved by its speed.");
    }

 

    @Test
    public void testReproduce() {
        omnivor.reproduce();
       
    }
    
    @Test
    public void testSimulationStep() {
        ecosystem.addEntity(herbivor);
        ecosystem.addEntity(carnivor);
        ecosystem.addEntity(omnivor);
        ecosystem.simulate(1); 


        assertTrue(herbivor.getEnergy() < 100, "Herbivor should lose energy during simulation step.");
    }


    
}
