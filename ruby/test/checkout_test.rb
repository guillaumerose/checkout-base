require "test/unit"

require "./lib/checkout.rb"

class TestCheckout < Test::Unit::TestCase
  def test_always_true
    checkout = Checkout.new
    assert_equal("ABC", checkout.process("aBc"))
  end
end