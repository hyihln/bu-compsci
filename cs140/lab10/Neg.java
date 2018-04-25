package lab10;

public class Neg extends Expr {
    private Expr expr;

    public Neg(Expr expr) {
        this.expr = expr;
    }

    public int eval() {
        int result = expr.eval();
        return result == 0 ? 1 : 0;
    }

	@Override
	public String toString() {
		return "neg("+expr+")";
	}
}