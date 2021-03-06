(set-logic LIA)



( synth-inv inv-f( ( n Int )( x Int )( y Int )( n_0 Int )( x_0 Int )( x_1 Int )( x_2 Int )( x_3 Int )( y_0 Int )( y_1 Int )( y_2 Int ) ) )

( define-fun pre-f ( ( n Int )( x Int )( y Int )( n_0 Int )( x_0 Int )( x_1 Int )( x_2 Int )( x_3 Int )( y_0 Int )( y_1 Int )( y_2 Int ) ) Bool
	( and
		( = x x_1 )
		( = x_1 1 )
	)
)

( define-fun trans-f ( ( n Int )( x Int )( y Int )( n_0 Int )( x_0 Int )( x_1 Int )( x_2 Int )( x_3 Int )( y_0 Int )( y_1 Int )( y_2 Int )( n! Int )( x! Int )( y! Int )( n_0! Int )( x_0! Int )( x_1! Int )( x_2! Int )( x_3! Int )( y_0! Int )( y_1! Int )( y_2! Int ) ) Bool
	( or
		( and
			( = x_2 x )
			( = y_1 y )
			( = x_2 x! )
			( = y_1 y! )
			( = n n_0 )
			( = n! n_0 )
			( = y y! )
		)
		( and
			( = x_2 x )
			( = y_1 y )
			( <= x_2 n_0 )
			( = y_2 ( - n_0 x_2 ) )
			( = x_3 ( + x_2 1 ) )
			( = x_3 x! )
			( = y_2 y! )
			(= n n_0 )
			(= n! n_0 )
		)
	)
)

( define-fun post-f ( ( n Int )( x Int )( y Int )( n_0 Int )( x_0 Int )( x_1 Int )( x_2 Int )( x_3 Int )( y_0 Int )( y_1 Int )( y_2 Int ) ) Bool
	( or
		( not
			( and
				( = n n_0 )
				( = x x_2)
				( = y y_1)
			)
		)
		( not
			( and
				( not ( <= x_2 n_0 ) )
				( > n_0 0 )
				( not ( >= y_1 0 ) )
			)
		)
	)
)

( inv-constraint inv-f pre-f trans-f post-f )
( check-synth )
