(set-logic LIA)



( synth-inv inv-f( ( c Int )( tmp Int )( c_0 Int )( c_1 Int )( c_2 Int )( c_3 Int )( c_4 Int )( c_5 Int ) ) )

( define-fun pre-f ( ( c Int )( tmp Int )( c_0 Int )( c_1 Int )( c_2 Int )( c_3 Int )( c_4 Int )( c_5 Int ) ) Bool
	( and
		( = c c_1 )
		( = c_1 0 )
	)
)

( define-fun trans-f ( ( c Int )( tmp Int )( c_0 Int )( c_1 Int )( c_2 Int )( c_3 Int )( c_4 Int )( c_5 Int )( c! Int )( tmp! Int )( c_0! Int )( c_1! Int )( c_2! Int )( c_3! Int )( c_4! Int )( c_5! Int ) ) Bool
	( or
		( and
			( = c_2 c )
			( = c_2 c! )
			( = c c! )
			(= tmp tmp! )
		)
		( and
			( = c_2 c )
			( not ( = c_2 40 ) )
			( = c_3 ( + c_2 1 ) )
			( = c_4 c_3 )
			( = c_4 c! )
			(= tmp tmp! )
		)
		( and
			( = c_2 c )
			( not ( not ( = c_2 40 ) ) )
			( = c_4 c_2 )
			( = c_4 c! )
			(= tmp tmp! )
		)
		( and
			( = c_2 c )
			( = c_2 40 )
			( = c_5 1 )
			( = c_4 c_5 )
			( = c_4 c! )
			(= tmp tmp! )
		)
		( and
			( = c_2 c )
			( not ( = c_2 40 ) )
			( = c_4 c_2 )
			( = c_4 c! )
			(= tmp tmp! )
		)
	)
)

( define-fun post-f ( ( c Int )( tmp Int )( c_0 Int )( c_1 Int )( c_2 Int )( c_3 Int )( c_4 Int )( c_5 Int ) ) Bool
	( or
		( not
			( = c c_2)
		)
		( not
			( and
				( < c_2 0 )
				( > c_2 40 )
				( not ( = c_2 40 ) )
			)
		)
	)
)

( inv-constraint inv-f pre-f trans-f post-f )
( check-synth )
