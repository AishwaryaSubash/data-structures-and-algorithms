public class Car {
    private String model;
    private Engine engine;
    private Transmission transmission;

    public Car(String model) {
        this.model = model;
        this.engine = new Engine();
        this.transmission = new Transmission();
    }

    public class Engine {
        private int horsepower;
        private String type;

        public Engine() {
            this.horsepower = 200; 
            this.type = "V6"; 
        }

        public int getHorsepower() {
            return horsepower;
        }

        public void setHorsepower(int horsepower) {
            this.horsepower = horsepower;
        }

        public String getType() {
            return type;
        }

        public void setType(String type) {
            this.type = type;
        }

        @Override
        public String toString() {
            return "Engine{" +
                   "horsepower=" + horsepower +
                   ", type='" + type + '\'' +
                   '}';
        }
    }

    public class Transmission {
        private String type;
        private int gears;

        public Transmission() {
            this.type = "Automatic"; 
            this.gears = 6; 
        }

        public String getType() {
            return type;
        }

        public void setType(String type) {
            this.type = type;
        }

        public int getGears() {
            return gears;
        }

        public void setGears(int gears) {
            this.gears = gears;
        }

        @Override
        public String toString() {
            return "Transmission{" +
                   "type='" + type + '\'' +
                   ", gears=" + gears +
                   '}';
        }
    }

    @Override
    public String toString() {
        return "Car{" +
               "model='" + model + '\'' +
               ", engine=" + engine +
               ", transmission=" + transmission +
               '}';
    }

    public static void main(String[] args) {
        Car car = new Car("Mustang");
        System.out.println(car);
        car.engine.setHorsepower(450);
        car.transmission.setType("Manual");
        System.out.println(car);
    }
}
