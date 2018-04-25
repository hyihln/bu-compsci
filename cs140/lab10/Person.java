package lab10;

public class Person implements Comparable<Person> {

    /**
     * Compares this person to other based on lastname then firstname
     *   (if lastnames are equal, compare firstnames)
     * @param other the other Person to compare this Person to
     * @return  < 0 if this Person is less than other
     *            0 if this Person is equal to other
     *          > 0 if this Person is greater than other
     */
	
	private String firstname;
	private String lastname;
	
    public Person(String firstname, String lastname) {
		super();
		this.firstname = firstname;
		this.lastname = lastname;
	}

	public String getFirstname() {
		return firstname;
	}

	public void setFirstname(String firstname) {
		this.firstname = firstname;
	}

	public String getLastname() {
		return lastname;
	}

	public void setLastname(String lastname) {
		this.lastname = lastname;
	}

	@Override
	public String toString(){
		return lastname+", "+firstname;
	}
	
	public int compareTo(Person other) {
        return lastname.compareTo(other.getLastname());
    }
}