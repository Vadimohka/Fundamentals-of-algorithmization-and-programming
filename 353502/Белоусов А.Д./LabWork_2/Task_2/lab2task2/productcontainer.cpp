#include "productcontainer.h"

ProductContainer::ProductContainer()
    : allProducts(new std::vector<Product *>)
{}

void ProductContainer::Clear()
{
    for (auto product : *allProducts) {
        delete product;
    }

    allProducts->clear();
}

void ProductContainer::AddProduct(Product product)
{
    allProducts->push_back(new Product(product));
}

void ProductContainer::EditProductAtPos(int64_t position, Product newProduct)
{
    *(allProducts->at(position)) = newProduct;
}

void ProductContainer::RemoveProductAtPos(int64_t position)
{
    delete allProducts->at(position);
    allProducts->erase(allProducts->begin() + position);
}

int64_t ProductContainer::FindProduct(Product product)
{
    int64_t size = allProducts->size();

    for (int iterator = 0; iterator < size; iterator++)
    {
        if (*(allProducts->at(iterator))->GetCode() == *product.GetCode() &&
            *(allProducts->at(iterator))->GetName() == *product.GetName() &&
            *(allProducts->at(iterator))->GetQuantity() == *product.GetQuantity() &&
            *(allProducts->at(iterator))->GetGroup()->GetName() == *product.GetGroup()->GetName() &&
            *(allProducts->at(iterator))->GetPrice() == *product.GetPrice())
        {
            return iterator;
        }
    }

    return size;
}

std::vector<Product *> *ProductContainer::GetAllProducts()
{
    return allProducts;
}

std::vector<Product *> *ProductContainer::SearchWithName(QString *name)
{
    std::vector<Product*>* answer = new std::vector<Product*>;

    for (auto product : *allProducts)
    {
        if (*product->GetName() == *name)
        {
            answer->push_back(new Product(*product));
        }
    }

    return answer;
}

std::vector<Product *> *ProductContainer::SearchWithLessQuantity(int64_t quantity)
{
    std::vector<Product*>* answer = new std::vector<Product*>;

    for (auto product : *allProducts)
    {
        if (*product->GetQuantity() < quantity)
        {
            answer->push_back(new Product(*product));
        }
    }

    return answer;
}

void ProductContainer::SortProductsByCode()
{
    sort(allProducts->begin(), allProducts->end(), [] (Product* first, Product* second) { return *first->GetCode() < *second->GetCode(); });
}

QString *ProductContainer::ToQString()
{
    QString* answer = new QString("");

    for (auto product : *allProducts)
    {
        answer->append(product->ToQString());
        answer->append('\n');
    }

    return answer;
}

void ProductContainer::FromQStringToInstance(QString *object)
{
    int64_t size = object->size();
    QString* current = new QString("");

    this->Clear();

    for (int iterator = 0;iterator<size;iterator++)
    {
        if (object->at(iterator) == '\n')
        {
            Product* newProduct = new Product;
            newProduct->FromQStringToInstance(current);
            allProducts->push_back(newProduct);
            current->clear();
        } else {
            current->append(object->at(iterator));
        }
    }

    delete current;
}


