/**
 * Represents the abstract base tier class that 
 * all other tiers inherent from.
 * 
 * Class hierarchy: "-->" - "Inherets from"
 * NoTier --> BaseTier
 * Gold, Platinum, SuperPlatinum --> NoTier
 * Platinum Pro --> Platinum
 * Super Executive Platinum --> Executive Platinum
 */

package tierpass;

abstract public class BaseTier {
    /**
     * 
     * @return - total miles earned
     */
    public abstract int getMiles();

    /**
     * 
     * @param miles - adds miles to current miles
     */
    public abstract void set_AddMiles(int miles);

    /**
     * 
     * @return - return # of canceled flights
     */
    public abstract int getCancelledFlights();

    /**
     * 
     * @param numCancelFlights - adds total cancelled flights by numCancelFlights
     */
    public abstract void set_AddCancelledFlights(int numCancelFlights);

    /**
     * 
     * @return - return total # of flights passenger has taken
     */
    public abstract int getFlights();

    /**
     * 
     * @param flights - adds flights to total flights
     */
    public abstract void set_AddFlights(int flights);

    /**
     * incremints the total flights by 1 and cancelled flights if true. 
     * Increases miles earned depending if they are in a tier.
     * Checks and updates tier if passenger qualifies for a tier upgrade. 
     * 
     * @param isCancelled - True if flight is cancelled, false otherwise
     */
    public abstract void addFlight(boolean isCancelled);

    /**
     * 
     * @return - returns the current tier that the tier object is.
     */
    public abstract String returnTier();
    

}
