(set-logic LIA)

( declare-const a Int )
( declare-const a! Int )
( declare-const c Int )
( declare-const c! Int )
( declare-const j Int )
( declare-const j! Int )
( declare-const k Int )
( declare-const k! Int )
( declare-const m Int )
( declare-const m! Int )

( declare-const a_0 Int )
( declare-const c_0 Int )
( declare-const j_0 Int )
( declare-const j_1 Int )
( declare-const k_0 Int )
( declare-const k_1 Int )
( declare-const m_0 Int )
( declare-const m_1 Int )
( declare-const m_2 Int )
( declare-const m_3 Int )

( define-fun inv-f( ( a Int )( c Int )( j Int )( k Int )( m Int ) ) Bool
SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
)

( define-fun pre-f ( ( a Int )( c Int )( j Int )( k Int )( m Int )( a_0 Int )( c_0 Int )( j_0 Int )( j_1 Int )( k_0 Int )( k_1 Int )( m_0 Int )( m_1 Int )( m_2 Int )( m_3 Int ) ) Bool
	( and
		( = j j_1 )
		( = k k_1 )
		( = j_1 0 )
		( = k_1 0 )
	)
)

( define-fun trans-f ( ( a Int )( c Int )( j Int )( k Int )( m Int )( a! Int )( c! Int )( j! Int )( k! Int )( m! Int )( a_0 Int )( c_0 Int )( j_0 Int )( j_1 Int )( k_0 Int )( k_1 Int )( m_0 Int )( m_1 Int )( m_2 Int )( m_3 Int ) ) Bool
	( or
		( and
			( = m_1 m )
			( = m_1 m! )
			( = k k_1 )
			( = k! k_1 )
			( = c c_0 )
			( = c! c_0 )
			( = a a! )
			( = j j! )
			( = m m! )
		)
		( and
			( = m_1 m )
			( < k_1 c_0 )
			( < m_1 a_0 )
			( = m_2 a_0 )
			( = m_3 m_2 )
			( = 1 2 )
			( = m_3 m! )
			(= a a_0 )
			(= a! a_0 )
			(= c c_0 )
			(= c! c_0 )
			(= j j_1 )
			(= j! j_1 )
			(= k k_1 )
			(= k! k_1 )
		)
		( and
			( = m_1 m )
			( < k_1 c_0 )
			( not ( < m_1 a_0 ) )
			( = m_3 m_1 )
			( = 1 2 )
			( = m_3 m! )
			(= a a_0 )
			(= a! a_0 )
			(= c c_0 )
			(= c! c_0 )
			(= j j_1 )
			(= j! j_1 )
			(= k k_1 )
			(= k! k_1 )
		)
	)
)

( define-fun post-f ( ( a Int )( c Int )( j Int )( k Int )( m Int )( a_0 Int )( c_0 Int )( j_0 Int )( j_1 Int )( k_0 Int )( k_1 Int )( m_0 Int )( m_1 Int )( m_2 Int )( m_3 Int ) ) Bool
	( or
		( not
			( and
				( = a a_0 )
				( = c c_0 )
				( = j j_1)
				( = k k_1)
				( = m m_1)
			)
		)
		( not
			( and
				( not ( < k_1 c_0 ) )
				( > c_0 0 )
				( not ( <= a_0 m_1 ) )
			)
		)
	)
)
SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
( assert ( not
	( =>
		( pre-f a c j k m a_0 c_0 j_0 j_1 k_0 k_1 m_0 m_1 m_2 m_3  )
		( inv-f a c j k m )
	)
))

SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
( assert ( not
	( =>
		( and
			( inv-f a c j k m )
			( trans-f a c j k m a! c! j! k! m! a_0 c_0 j_0 j_1 k_0 k_1 m_0 m_1 m_2 m_3 )
		)
		( inv-f a! c! j! k! m! )
	)
))

SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
( assert ( not
	( =>
		( inv-f a c j k m  )
		( post-f a c j k m a_0 c_0 j_0 j_1 k_0 k_1 m_0 m_1 m_2 m_3 )
	)
))

