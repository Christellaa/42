# base_template.py

template = """.. title:: {function_name}

.. function:: {function_name}({parameters})

   {description}

   **Parameters:**

{param_descriptions}

   :return: {return_description}

   **Example:**

   .. code-block:: c

       {example}

   **Note:**

   {notes}

   **Related functions:**

   {related_functions}
"""
