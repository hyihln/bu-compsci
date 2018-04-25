package lab08;

public class Card {
	public static enum Suit{Hearts, Diamonds, Clubs, Spades};
	private Suit suit;
	private int value;
	
	public Card(Suit suit, int value) {
		super();
		this.suit = suit;
		this.value = value;
		
		if (value < 2 || value > 11){
			throw new IllegalArgumentException();
		}
	}

	public Suit getSuit() {
		return suit;
	}

	public void setSuit(Suit suit) {
		this.suit = suit;
	}

	public int getValue() {
		return value;
	}

	public void setValue(int value) {
		this.value = value;
	}
	
	@Override
	public boolean equals(Object other){
		if(other instanceof Card){
			Card objVar = (Card)other;
			return true;
		}
		else{
			return false;
		}
	}
	
	@Override
	public int hashCode(){
		return 31*suit.hashCode()+7*Integer.hashCode(value);
	}
	
	@Override
	public String toString(){
		String newString = "";
		if(value == 11){
			newString = newString+"Ace"+" of "+suit.toString();
			return newString;
		}
		else{
			newString = newString+value+" of "+suit.toString();
			return newString;
		}
	}
	
	public static void main(String[] args){
		Card card01 = new Card(Suit.Spades, 11);
		Card card02 = new Card(Suit.Hearts, 5);
		System.out.println(card01);
		System.out.println(card02);
	}
}
