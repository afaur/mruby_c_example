puts "Commands are:"
puts "add, exit, or list"

db = SQLite3::Database.new('db/foo.db')
continue = true
while continue
  print "> "
  path = MyModule::getstring().chomp
  if path == "add"
    print "input> "
    input = MyModule::getstring().chomp
    db.execute_batch('insert into foo(text) values(?)', input)
  elsif path == "exit"
    continue = false
  else
    db.execute('select * from foo') do |row, fields|
      puts row
    end
  end
end
db.close
