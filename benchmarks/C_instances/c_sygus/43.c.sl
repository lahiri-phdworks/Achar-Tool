(set-logic LIA)

( declare-primed-var c Int )
( declare-primed-var n Int )
( declare-primed-var tmp Int )

( declare-primed-var c_0 Int )
( declare-primed-var c_1 Int )
( declare-primed-var c_2 Int )
( declare-primed-var c_3 Int )
( declare-primed-var c_4 Int )
( declare-primed-var c_5 Int )
( declare-primed-var n_0 Int )

( synth-inv inv-f( ( c Int )( n Int )( tmp Int )( c_0 Int )( c_1 Int )( c_2 Int )( c_3 Int )( c_4 Int )( c_5 Int )( n_0 Int ) ) )

( define-fun pre-f ( ( c Int )( n Int )( tmp Int )( c_0 Int )( c_1 Int )( c_2 Int )( c_3 Int )( c_4 Int )( c_5 Int )( n_0 Int ) ) Bool
	( and
		( = c c_1 )
		( = n n_0 )
		( > n_0 0 )
		( = c_1 0 )
	)
)

( define-fun trans-f ( ( c Int )( n Int )( tmp Int )( c_0 Int )( c_1 Int )( c_2 Int )( c_3 Int )( c_4 Int )( c_5 Int )( n_0 Int )( c! Int )( n! Int )( tmp! Int )( c_0! Int )( c_1! Int )( c_2! Int )( c_3! Int )( c_4! Int )( c_5! Int )( n_0! Int ) ) Bool
	( or
		( and
			( = c_2 c )
			( = c_2 c! )
			( = c c! )
			( = n n! )
			(= tmp tmp! )
		)
		( and
			( = c_2 c )
			( > c_2 n_0 )
			( = c_3 ( + c_2 1 ) )
			( = c_4 c_3 )
			( = c_4 c! )
			(= n n_0 )
			(= n! n_0 )
			(= tmp tmp! )
		)
		( and
			( = c_2 c )
			( not ( > c_2 n_0 ) )
			( = c_4 c_2 )
			( = c_4 c! )
			(= n n_0 )
			(= n! n_0 )
			(= tmp tmp! )
		)
		( and
			( = c_2 c )
			( = c_2 n_0 )
			( = c_5 1 )
			( = c_4 c_5 )
			( = c_4 c! )
			(= n n_0 )
			(= n! n_0 )
			(= tmp tmp! )
		)
		( and
			( = c_2 c )
			( not ( = c_2 n_0 ) )
			( = c_4 c_2 )
			( = c_4 c! )
			(= n n_0 )
			(= n! n_0 )
			(= tmp tmp! )
		)
	)
)

( define-fun post-f ( ( c Int )( n Int )( tmp Int )( c_0 Int )( c_1 Int )( c_2 Int )( c_3 Int )( c_4 Int )( c_5 Int )( n_0 Int ) ) Bool
	( or
		( not
			( and
				( = c c_2)
				( = n n_0)
			)
		)
		( not
			( and
				( = c_2 n_0 )
				( not ( > n_0 -1 ) )
			)
		)
	)
)

( inv-constraint inv-f pre-f trans-f post-f )
( check-synth )
