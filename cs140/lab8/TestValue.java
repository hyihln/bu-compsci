package lab08;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

import lab08.Card.Suit;

public class TestValue {

	@Test
	public void Test1() {
		BlackjackHand myHand = new BlackjackHand();
		Card card1 = new Card(Suit.Hearts, 2);
		myHand.addCard(card1);
		
		Card card2 = new Card(Suit.Hearts, 4);
		myHand.addCard(card2);
		
		assertEquals(6,myHand.value());
	}

	@Test
	public void Test2() {
		BlackjackHand myHand = new BlackjackHand();
		Card card1 = new Card(Suit.Hearts, 11);
		myHand.addCard(card1);
		
		Card card2 = new Card(Suit.Hearts, 10);
		myHand.addCard(card2);
		
		assertEquals(21,myHand.value());
	}
	
	@Test
	public void Test3() {
		BlackjackHand myHand = new BlackjackHand();
		Card card1 = new Card(Suit.Hearts, 11);
		myHand.addCard(card1);
		
		Card card2 = new Card(Suit.Hearts, 11);
		myHand.addCard(card2);
		
		assertEquals(12,myHand.value());
	}
	
	@Test
	public void Test4() {
		BlackjackHand myHand = new BlackjackHand();
		Card card1 = new Card(Suit.Hearts, 11);
		myHand.addCard(card1);
		
		Card card2 = new Card(Suit.Hearts, 11);
		myHand.addCard(card2);
		
		Card card3 = new Card(Suit.Spades, 11);
		myHand.addCard(card3);
		
		assertEquals(13,myHand.value());
	}
	
	@Test
	public void Test5() {
		BlackjackHand myHand = new BlackjackHand();
		Card card1 = new Card(Suit.Hearts, 10);
		myHand.addCard(card1);
		
		Card card2 = new Card(Suit.Hearts, 10);
		myHand.addCard(card2);
		
		Card card3 = new Card(Suit.Spades, 2);
		myHand.addCard(card3);
		
		assertEquals(22,myHand.value());
	}
	
	@Test
	public void Test6() {
		BlackjackHand myHand = new BlackjackHand();
		Card card1 = new Card(Suit.Hearts, 10);
		myHand.addCard(card1);
		
		Card card2 = new Card(Suit.Hearts, 10);
		myHand.addCard(card2);
		
		Card card3 = new Card(Suit.Spades, 11);
		myHand.addCard(card3);
		
		assertEquals(21,myHand.value());
	}
}
