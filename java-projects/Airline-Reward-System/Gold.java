package tierpass;

/**
 * Represents A gold rewards tier
 * Every cancelled flight --> 1000+ reward miles
 */
public class Gold extends NoTier {
    /**
     * Creates a new Tier of type Gold
     * Calls super --> sets miles, cancelled flights and total flights to 0
     */
    public Gold(){
        super();
    }

    /**
     * Creates a new Tier of Type Gold
     * @param miles - # of reward miles earned 
     * @param numCancelFlights - # of cancelled flights
     * @param totalFlights - # of total flights taken
     * 
     * Sets the class fields to custom inputs by class declaration
     */
    public Gold(int miles, int numCancelFlights, int totalFlights){
        super(miles, numCancelFlights, totalFlights);
    }
    
    /**
     * Adds a flight to the tier object
     * incremints the total flights by 1 and cancelled flights if true. 
     * Increases miles earned by 1000. 
     * 
     * @param isCancelled - True if flight is cancelled, false otherwise
     */
    @Override
    public void addFlight(boolean isCancelled){
        
        super.set_AddFlights(1); // += 1 flight to total flights
        if (isCancelled){
            super.set_AddCancelledFlights(1);  // += 1 to totalCancelled flights
            super.set_AddMiles(1000); // += 1000 reward miles
        }
    }
    
    /**
     * 
     * @return - returns the current tier which is "Gold"
     */
    @Override
    public String returnTier(){
        return "Gold ";
    }
    
}
