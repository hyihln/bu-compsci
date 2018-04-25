package lab10;

public class Num extends Expr {
    private int value;

    public Num(int value) {
        this.value = value;
    }

    public int eval() {
        return value;
    }

	@Override
	public String toString() {
		return ""+value;
	}
}