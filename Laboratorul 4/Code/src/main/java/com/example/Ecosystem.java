package com.example;

import java.util.ArrayList;
import java.util.Random;

public class Ecosystem {
    private ArrayList<EntityEcosystem> entities;
    private int time;
    private Random random;

    public Ecosystem() {
        this.entities = new ArrayList<>();
        this.time = 0;
        this.random = new Random();
    }

    public void addEntity(EntityEcosystem entity) {
        entities.add(entity);
    }

    public void removeEntity(EntityEcosystem entity) {
        if (entity.isDead()) {
            entities.remove(entity);
            System.out.println(entity.getName() + " is dead and removed from the ecosystem.");
        }
    }

    public void simulate(int steps) {
        for (int step = 0; step < steps; step++) {
            System.out.println("Simulation step " + time);
            time++; 

            for (int i = 0; i < entities.size(); i++) {
                EntityEcosystem entity = entities.get(i);
                entity.act();

                if (entity instanceof Animal) {
                    Animal animal = (Animal) entity;

                    for (int j = 0; j < entities.size(); j++) {
                        if (i != j) { 
                            EntityEcosystem otherEntity = entities.get(j);
                            if (otherEntity instanceof Animal) {
                                Animal otherAnimal = (Animal) otherEntity;

                                if (animal instanceof Carnivore && otherAnimal instanceof Herbivor) {
                                    ((Carnivore) animal).attack(otherAnimal);
                                }

                                if (animal instanceof Omnivore && otherAnimal instanceof Omnivore) {
                                    animal.reproduce();
                                }
                            }
                        }
                    }

                    if (entity.isDead()) {
                        removeEntity(entity);
                        i--;  
                    }
                }
            }

            generateRandomEvents();
        }
    }

    private void generateRandomEvents() {
        int eventChance = random.nextInt(100);
        if (eventChance < 10) {
            System.out.println("A storm has occurred! Energy of all entities decreases.");
            for (EntityEcosystem entity : entities) {
                entity.reduceEnergy(10);
            }
        } else if (eventChance < 20) {
            System.out.println("A drought has occurred! Herbivores lose more energy.");
            for (EntityEcosystem entity : entities) {
                if (entity instanceof Herbivor) {
                    entity.reduceEnergy(15);
                }
            }
        } else if (eventChance < 30) {
            System.out.println("A new species has appeared!");
            EntityEcosystem newEntity = createRandomEntity();
            addEntity(newEntity);
            System.out.println("New entity added: " + newEntity.getName());
        }
    }

    private EntityEcosystem createRandomEntity() {
        // Creare random x, y, energy, speed, age
        int x = random.nextInt(100);
        int y = random.nextInt(100);
        double energy = random.nextInt(100);
        int speed = random.nextInt(100);
        int age = random.nextInt(10);
        String type = "generic";

        int typeChoice = random.nextInt(3);
        switch (typeChoice) {
            case 0:
                return new Herbivor("New Herbivore", energy, x, y, 0.8f, speed, "herb");
            case 1:
                return new Carnivore("New Carnivore", energy, x, y, 0.7f, speed, "meat");
            case 2:
                return new Omnivore("New Omnivore", energy, x, y, 0.75f, speed, "mixed");
            default:
                return null;
        }
    }

    public void displayEcosystem() {
        System.out.println("Current state of the ecosystem:");
        if (entities.isEmpty()) {
            System.out.println("The ecosystem is empty.");
        } else {
            for (EntityEcosystem entity : entities) {
                System.out.println("Entity: " + entity.getName() + ", Energy: " + entity.getEnergy() + ", Position: (" + entity.getX() + ", " + entity.getY() + ")");
            }
        }
    }
}
