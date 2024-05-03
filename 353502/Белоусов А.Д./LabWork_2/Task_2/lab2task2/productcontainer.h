#ifndef PRODUCTCONTAINER_H
#define PRODUCTCONTAINER_H

#include "product.h"
#include "convertibleinstance.h"
#include <vector>

class ProductContainer : public ConvertibleInstance
{
    std::vector<Product*>* allProducts{new std::vector<Product*>};
public:
    ProductContainer();
    ~ProductContainer() override = default;
    void Clear();
    void AddProduct(Product product);
    void EditProductAtPos(int64_t position, Product newProduct);
    void RemoveProductAtPos(int64_t position);
    int64_t FindProduct(Product product);
    std::vector<Product*>* GetAllProducts();
    std::vector<Product*>* SearchWithName(QString* name);
    std::vector<Product*>* SearchWithLessQuantity(int64_t quantity);
    void SortProductsByCode();

    QString *ToQString() override;
    void FromQStringToInstance(QString* object) override;
};

#endif // PRODUCTCONTAINER_H
