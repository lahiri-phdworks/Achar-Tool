(set-logic LIA)



( synth-inv inv-f( ( size Int )( x Int )( y Int )( z Int )( size_0 Int )( x_0 Int )( x_1 Int )( x_2 Int )( x_3 Int )( y_0 Int )( y_1 Int )( y_2 Int )( y_3 Int )( z_0 Int ) ) )

( define-fun pre-f ( ( size Int )( x Int )( y Int )( z Int )( size_0 Int )( x_0 Int )( x_1 Int )( x_2 Int )( x_3 Int )( y_0 Int )( y_1 Int )( y_2 Int )( y_3 Int )( z_0 Int ) ) Bool
	( and
		( = x x_1 )
		( = x_1 0 )
	)
)

( define-fun trans-f ( ( size Int )( x Int )( y Int )( z Int )( size_0 Int )( x_0 Int )( x_1 Int )( x_2 Int )( x_3 Int )( y_0 Int )( y_1 Int )( y_2 Int )( y_3 Int )( z_0 Int )( size! Int )( x! Int )( y! Int )( z! Int )( size_0! Int )( x_0! Int )( x_1! Int )( x_2! Int )( x_3! Int )( y_0! Int )( y_1! Int )( y_2! Int )( y_3! Int )( z_0! Int ) ) Bool
	( or
		( and
			( = x_2 x )
			( = y_1 y )
			( = x_2 x! )
			( = y_1 y! )
			( = size size_0 )
			( = size! size_0 )
			( = y y! )
			( = z z! )
		)
		( and
			( = x_2 x )
			( = y_1 y )
			( < x_2 size_0 )
			( = x_3 ( + x_2 1 ) )
			( <= z_0 y_1 )
			( = y_2 z_0 )
			( = y_3 y_2 )
			( = x_3 x! )
			( = y_3 y! )
			(= size size_0 )
			(= size! size_0 )
			(= z z_0 )
			(= z! z_0 )
		)
		( and
			( = x_2 x )
			( = y_1 y )
			( < x_2 size_0 )
			( = x_3 ( + x_2 1 ) )
			( not ( <= z_0 y_1 ) )
			( = y_3 y_1 )
			( = x_3 x! )
			( = y_3 y! )
			(= size size_0 )
			(= size! size_0 )
			(= z z_0 )
			(= z! z_0 )
		)
	)
)

( define-fun post-f ( ( size Int )( x Int )( y Int )( z Int )( size_0 Int )( x_0 Int )( x_1 Int )( x_2 Int )( x_3 Int )( y_0 Int )( y_1 Int )( y_2 Int )( y_3 Int )( z_0 Int ) ) Bool
	( or
		( not
			( and
				( = size size_0 )
				( = x x_2)
				( = y y_1)
				( = z z_0 )
			)
		)
		( not
			( and
				( not ( < x_2 size_0 ) )
				( > size_0 0 )
				( not ( >= z_0 y_1 ) )
			)
		)
	)
)

( inv-constraint inv-f pre-f trans-f post-f )
( check-synth )
