# You can create classes and functions to track expenses and generate reports.
# This is a simplified version.
class ExpenseTracker:
    def __init__(self):
        self.expenses = []

    def add_expense(self, item, amount):
        self.expenses.append({'item': item, 'amount': amount})

    def get_total_expenses(self):
        return sum(item['amount'] for item in self.expenses)

tracker = ExpenseTracker()
tracker.add_expense('Groceries', 50)
tracker.add_expense('Dining out', 30)
print(f"Total expenses: ${tracker.get_total_expenses()}")
