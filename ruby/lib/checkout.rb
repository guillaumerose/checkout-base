class Checkout
  def process(a)
    a.upcase
  end
end

if $0 == __FILE__
  checkout = Checkout.new
  loop {
    print "> "
    puts checkout.process(gets)
  }
end