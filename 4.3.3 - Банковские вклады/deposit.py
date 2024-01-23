# Программирование на языке высокого уровня (Python).
# Задание №______. Вариант !!!
#
# Выполнил: Фамилия И.О.
# Группа: !!!
# E-mail: !!!


class TimeDeposit:
    """Абстрактный класс - срочный вклад.

    https://ru.wikipedia.org/wiki/Срочный_вклад.

    Поля:
      - self.name (str): наименование;
      - self._interest_rate (float): процент по вкладу (0; 100];
      - self._period_limit (tuple (int, int)):
            допустимый срок вклада в месяцах [от; до);
      - self._sum_limit (tuple (float, float)):
            допустимая сумма вклада [от; до).
    Свойства:
      - self.currency (str): знак/наименование валюты.
    Методы:
      - self._check_self(initial_sum, period): проверяет соответствие данных
            ограничениям вклада;
      - self.get_profit(initial_sum, period): возвращает прибыль по вкладу;
      - self.get_sum(initial_sum, period):
            возвращает сумму по окончании вклада.
    """

    def __init__(self, name, _interest_rate, _period_limit, sum_limit):
        """Инициализировать атрибуты класса."""
        self.name = name
        self._interest_rate = _interest_rate
        self._period_limit = _period_limit
        self._sum_limit = sum_limit

        # Проверить значения
        self._check_self()

    def __str__(self):
        """Вернуть строкое представление депозита.

        Формат вывода:

        Наименование:       Срочный Вклад
        Валюта:             руб.
        Процентная ставка:  5
        Срок (мес.):        [6; 18)
        Сумма:              [1,000; 100,000)
        """
        str_value1 = (f'Наименование: {self.name}'
                      f'Валюта: руб.'
                      f'Процентная ставка: {self.interest_rate}'
                      f'Срок (мес.): {self.period_limit}'
                      f'Сумма: {self.sum_limit}'
                     )
        return str_value1

    @property
    def currency(self):
        return "руб."  # Не изменяется

    def _check_self(self):
        """Проверить, что данные депозита являются допустимыми."""
        assert 0 < self._interest_rate <= 100, \
            "Неверно указан процент по вкладу!"
        assert 1 <= self._period_limit[0] < self._period_limit[1], \
            "Неверно указаны ограничения по сроку вклада!"
        assert 0 < self._sum_limit[0] <= self._sum_limit[1], \
            "Неверно указаны ограничения по сумме вклада!"

    def _check_user_params(self, initial_sum, period):
        """Проверить, что данные депозита соответствуют его ограничениям."""
        is_sum_ok = self._sum_limit[0] <= initial_sum < self._sum_limit[1]
        is_period_ok = self._period_limit[0] <= period < self._period_limit[1]
        assert is_sum_ok and is_period_ok, "Условия вклада не соблюдены!"

    def get_profit(self, initial_sum, period):
        """Вернуть прибыль по вкладу вклада клиента.

        Параметры:
          - initial_sum (float): первоначальная сумма;
          - period (int): количество месяцев размещения вклада.

        Формула:
          первоначальная_сумма * % / 100 * период / 12
        """

        # Проверить, укладывается ли вклад в ограничения
        self._check_user_params(initial_sum, period)
        # Выполнить расчет
        return initial_sum * self._interest_rate / 100 * period / 12

    def get_sum(self, initial_sum, period):
        """Вернуть сумму вклада клиента после начисления прибыли.

        Параметры:
          - initial_sum (float): первоначальная сумма;
          - period (int): количество месяцев размещения вклада.
        """
        # Выполнить расчет
        return initial_sum + self.get_profit(initial_sum, period)


class BonusTimeDeposit(TimeDeposit):
    """Cрочный вклад c получением бонуса к концу срока вклада.

    Бонус начисляется как % от прибыли, если вклад больше определенной суммы.

    Атрибуты:
      - self._bonus (dict ("percent"=int, "sum"=float)):
        % от прибыли, мин. сумма;
    """

    def __init__(self, name, _interest_rate, _period_limit, sum_limit, bonus):
        """Инициализировать атрибуты класса."""
        self.bonus = bonus
        super().__init__(name, _interest_rate, _period_limit, sum_limit)

    def __str__(self):
        """Вернуть строковое представление депозита.

        К информации о родителе добавляется информацию о бонусе.

        Формат вывода:

        Наименование:       Бонусный Вклад
        Валюта:             руб.
        Процентная ставка:  5
        Срок (мес.):        [6; 18)
        Сумма:              [1,000; 100,000)
        Бонус (%):          5
        Бонус (мин. сумма): 2,000
        """
        parent_str = super().__str__()
        bonus_str = f"Бонус (%): {self.bonus['percent']}\nБонус (мин. сумма): {self.bonus['sum']}"
        return (
            f"Бонусный Вклад\n"
            f"{parent_str}\n"
            f"{bonus_str}"
        )

    def _check_self(self):
        """Проверить, что данные депозита являются допустимыми.

        Дополняем родительский метод проверкой бонуса.
        """
        """Проверить, что данные депозита являются допустимыми."""
        super()._check_self()
        assert 2000 <= self.bonus["sum"], "Неверно указана минимальная сумма для действия бонуса."

    def get_profit(self, initial_sum, period):
        """Вернуть прибыль по вкладу вклада клиента.

        Параметры:
          - initial_sum (float): первоначальная сумма;
          - period (int): количество месяцев размещения вклада.

        Формула:
          - прибыль = сумма * процент / 100 * период / 12

        Для подсчета прибыли используется родительский метод.
        Далее, если первоначальная сумма > необходимой,
        начисляется бонус.
        """
        # Проверить, укладывается ли вклад в ограничения
        self._check_user_params(initial_sum, period)

        parent_profit = super().get_profit(initial_sum, period)
        if initial_sum > 2000:
            return initial_sum * self.bonus['percent'] / 100 * period / 12 + parent_profit
        return parent_profit

    def get_sum(self, initial_sum, period):
        """Вернуть сумму вклада клиента после начисления прибыли.

        Параметры:
          - initial_sum (float): первоначальная сумма;
          - period (int): количество месяцев размещения вклада.
        """
        # Выполнить расчет
        return initial_sum + self.get_profit(initial_sum, period)

class CompoundTimeDeposit(TimeDeposit):
    """Cрочный вклад c ежемесячной капитализацией процентов."""
    def __init__(self,name, interest_rate, period_limit, sum_limit):
        super().__init__(name, interest_rate, period_limit, sum_limit)
        self.capitalization = True



    def __str__(self):
        """Вернуть строкое представление депозита.

        К информации о родителе добавляется информация о капитализации.

        Формат вывода:

        Наименование:       Вклад с Капитализацией
        Валюта:             руб.
        Процентная ставка:  5
        Срок (мес.):        [6; 18)
        Сумма:              [1,000; 100,000)
        Капитализация %   : Да
        """
        parent_c_str = super().__str__()
        capitalized_str = "Капитализация %: Да"
        return (
            f"{parent_c_str}"
            f"\n Капитализация %: Да"
        )

    def get_profit(self, initial_sum, period):
        """Вернуть прибыль по вкладу вклада клиента.

        Параметры:
          - initial_sum (float): первоначальная сумма;
          - period (int): количество месяцев размещения вклада.

        Родительский метод для подсчета прибыли использовать не нужно,
        переопределив его полностью - расчет осуществляется по новой формуле.
        Капитализация процентов осуществляется ежемесячно.

        Нужно не забыть про самостоятельный вызов проверки параметров.

        Формула:
          первоначальная_сумма * (1 + % / 100 / 12) ** период -
          первоначальная_сумма
        """
        # Проверить, укладывается ли вклад в ограничения
        self._check_user_params(initial_sum, period)
        
        return initial_sum * (1 + self._interest_rate / 100 / 12) ** period - initial_sum

# ---


deposits_data = dict(interest_rate=5, period_limit=(6, 18),
                     sum_limit=(1000, 100000))

# Список имеющихся депозитов
deposits = (
    TimeDeposit("Сохраняй", _interest_rate=5,
                _period_limit=(6, 18),
                sum_limit=(1000, 100000)),
    BonusTimeDeposit("Бонусный ", _interest_rate=5, _period_limit=(6, 18), sum_limit=(1000, 100000),
                bonus=dict(percent=5, sum=2000)),
    CompoundTimeDeposit("С капитализацией", **deposits_data)
)
