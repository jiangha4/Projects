union float_bits{
	float f;
	unsigned int bits;
};

void print_hex( float f){
	union float_bits t;
	t.f = f;
	print f("The float looks like 0x%x in hex.\n", t.bits);
}
