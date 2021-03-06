(set-logic LIA)



( synth-inv inv-f( ( n Int )( x Int )( n_0 Int )( x_0 Int )( x_1 Int )( x_2 Int )( x_3 Int ) ) )

( define-fun pre-f ( ( n Int )( x Int )( n_0 Int )( x_0 Int )( x_1 Int )( x_2 Int )( x_3 Int ) ) Bool
	( and
		( = n n_0 )
		( = x x_1 )
		( = x_1 n_0 )
	)
)

( define-fun trans-f ( ( n Int )( x Int )( n_0 Int )( x_0 Int )( x_1 Int )( x_2 Int )( x_3 Int )( n! Int )( x! Int )( n_0! Int )( x_0! Int )( x_1! Int )( x_2! Int )( x_3! Int ) ) Bool
	( or
		( and
			( = x_2 x )
			( = x_2 x! )
			( = n n! )
		)
		( and
			( = x_2 x )
			( > x_2 0 )
			( = x_3 ( - x_2 1 ) )
			( = x_3 x! )
			(= n n_0 )
			(= n! n_0 )
		)
	)
)

( define-fun post-f ( ( n Int )( x Int )( n_0 Int )( x_0 Int )( x_1 Int )( x_2 Int )( x_3 Int ) ) Bool
	( or
		( not
			( and
				( = n n_0)
				( = x x_2)
			)
		)
		( not
			( and
				( not ( > x_2 0 ) )
				( not ( = x_2 0 ) )
				( not ( < n_0 0 ) )
			)
		)
	)
)

( inv-constraint inv-f pre-f trans-f post-f )
( check-synth )
