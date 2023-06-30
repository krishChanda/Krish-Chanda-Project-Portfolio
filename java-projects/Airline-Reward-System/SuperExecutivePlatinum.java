package tierpass;

/**
 * Represents A Super Executive Platinum rewards tier
 * If earned --> all flight reward miles are doubled &
 * every cancelled flight --> 2000+ reward miles
 * Only Earned at end of year if Passenger has not complained
 */
public class SuperExecutivePlatinum extends ExecutivePlatinum{
    /**
     * Creates a new Tier of type Super Executive Platinum
     * Calls super --> sets miles, cancelled flights and total flights to 0 
     *  --> calls to NoTier Super() from Platinum Super()
     */
    public SuperExecutivePlatinum(){
        super();
    }

    /**
     * Creates a new Tier of Type Super Executive Platinum
     * @param miles - # of reward miles earned 
     * @param numCancelFlights - # of cancelled flights
     * @param totalFlights - # of total flights taken
     * 
     * Sets the class fields to custom inputs by class declaration
     */
    public SuperExecutivePlatinum(int miles, int numCancelFlights, int totalFlights){
        super(miles*2, numCancelFlights, totalFlights); // doubles the number of reward miles earned
    }

    /**
     * Adds a flight to the tier object
     * incremints the total flights by 1 and cancelled flights if true. 
     * Increases miles earned by 2000. 
     * 
     * @param isCancelled - True if flight is cancelled, false otherwise
     */
    @Override
    public void addFlight(boolean isCancelled){
        super.set_AddFlights(1); // += 1 to total flights 
        if (isCancelled){
            super.set_AddCancelledFlights(1); // += 1 to cancelled flights 
            super.set_AddMiles(2000); // += 2000 to miles earned
        }
    }

    /**
     * 
     * @return - returns the current tier which is "Super Executive Platinum"
     */
    @Override
    public String returnTier(){
        return "Super Executive Platinum ";
    }
}
