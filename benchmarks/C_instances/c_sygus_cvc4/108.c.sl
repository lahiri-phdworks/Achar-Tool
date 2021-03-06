(set-logic LIA)



( synth-inv inv-f( ( a Int )( c Int )( j Int )( k Int )( m Int )( a_0 Int )( c_0 Int )( j_0 Int )( j_1 Int )( k_0 Int )( k_1 Int )( k_2 Int )( k_3 Int )( m_0 Int )( m_1 Int )( m_2 Int )( m_3 Int ) ) )

( define-fun pre-f ( ( a Int )( c Int )( j Int )( k Int )( m Int )( a_0 Int )( c_0 Int )( j_0 Int )( j_1 Int )( k_0 Int )( k_1 Int )( k_2 Int )( k_3 Int )( m_0 Int )( m_1 Int )( m_2 Int )( m_3 Int ) ) Bool
	( and
		( = a a_0 )
		( = j j_1 )
		( = k k_1 )
		( = m m_0 )
		( <= a_0 m_0 )
		( = j_1 0 )
		( = k_1 0 )
	)
)

( define-fun trans-f ( ( a Int )( c Int )( j Int )( k Int )( m Int )( a_0 Int )( c_0 Int )( j_0 Int )( j_1 Int )( k_0 Int )( k_1 Int )( k_2 Int )( k_3 Int )( m_0 Int )( m_1 Int )( m_2 Int )( m_3 Int )( a! Int )( c! Int )( j! Int )( k! Int )( m! Int )( a_0! Int )( c_0! Int )( j_0! Int )( j_1! Int )( k_0! Int )( k_1! Int )( k_2! Int )( k_3! Int )( m_0! Int )( m_1! Int )( m_2! Int )( m_3! Int ) ) Bool
	( or
		( and
			( = k_2 k )
			( = m_1 m )
			( = k_2 k! )
			( = m_1 m! )
			( = c c_0 )
			( = c! c_0 )
			( = a a! )
			( = j j! )
			( = m m! )
		)
		( and
			( = k_2 k )
			( = m_1 m )
			( < k_2 c_0 )
			( < m_1 a_0 )
			( = m_2 a_0 )
			( = m_3 m_2 )
			( = k_3 ( + k_2 1 ) )
			( = k_3 k! )
			( = m_3 m! )
			(= a a_0 )
			(= a! a_0 )
			(= c c_0 )
			(= c! c_0 )
			(= j j_1 )
			(= j! j_1 )
		)
		( and
			( = k_2 k )
			( = m_1 m )
			( < k_2 c_0 )
			( not ( < m_1 a_0 ) )
			( = m_3 m_1 )
			( = k_3 ( + k_2 1 ) )
			( = k_3 k! )
			( = m_3 m! )
			(= a a_0 )
			(= a! a_0 )
			(= c c_0 )
			(= c! c_0 )
			(= j j_1 )
			(= j! j_1 )
		)
	)
)

( define-fun post-f ( ( a Int )( c Int )( j Int )( k Int )( m Int )( a_0 Int )( c_0 Int )( j_0 Int )( j_1 Int )( k_0 Int )( k_1 Int )( k_2 Int )( k_3 Int )( m_0 Int )( m_1 Int )( m_2 Int )( m_3 Int ) ) Bool
	( or
		( not
			( and
				( = a a_0)
				( = c c_0 )
				( = j j_1)
				( = k k_2)
				( = m m_1)
			)
		)
		( not
			( and
				( not ( < k_2 c_0 ) )
				( not ( <= a_0 m_1 ) )
			)
		)
	)
)

( inv-constraint inv-f pre-f trans-f post-f )
( check-synth )
