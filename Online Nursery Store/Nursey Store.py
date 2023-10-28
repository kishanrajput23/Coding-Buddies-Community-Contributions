class Product:
    def __init__(self, name, price, category):
        self.name = name
        self.price = price
        self.category = category

class NurseryStore:
    def __init__(self):
        self.products = []

    def add_product(self, name, price, category):
        product = Product(name, price, category)
        self.products.append(product)

    def list_products(self, category=None):
        if category:
            print(f"{category} products:")
            filtered_products = [p for p in self.products if p.category == category]
        else:
            print("All products:")
            filtered_products = self.products

        for i, product in enumerate(filtered_products, start=1):
            print(f"{i}. {product.name} - ${product.price}")

    def add_to_cart(self, index):
        if 1 <= index <= len(self.products):
            product = self.products[index - 1]
            self.cart.append(product)
            print(f"{product.name} added to the cart.")

    def view_cart(self):
        if not self.cart:
            print("Your cart is empty.")
        else:
            total = sum(product.price for product in self.cart)
            print("Products in your cart:")
            for i, product in enumerate(self.cart, start=1):
                print(f"{i}. {product.name} - ${product.price}")
            print(f"Total: ${total}")

if __name__ == "__main__":
    nursery = NurseryStore()
    nursery.cart = []  # Initialize the cart

    # Add some products to the store
    nursery.add_product("Rose Plant", 10, "Plants (Outdoor)")
    nursery.add_product("Fern Plant", 12, "Plants (Indoor)")
    nursery.add_product("Terracotta Pot", 5, "Pots")
    nursery.add_product("Wooden Pot Stand", 15, "Pot Stands")

    while True:
        print("\nOptions:")
        print("1. List all products")
        print("2. List products by category")
        print("3. Add to cart")
        print("4. View cart")
        print("5. Exit")
        choice = input("Enter your choice: ")

        if choice == "1":
            nursery.list_products()
        elif choice == "2":
            category = input("Enter the category (or press Enter for all): ")
            nursery.list_products(category)
        elif choice == "3":
            index = int(input("Enter the product number to add to cart: "))
            nursery.add_to_cart(index)
        elif choice == "4":
            nursery.view_cart()
        elif choice == "5":
            print("Thank you for shopping with us!")
            break
        else:
            print("Invalid choice. Please try again.")
